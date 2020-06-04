/* Copyright (c) 2019, Guillaume Champagne
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

//#define NO_VERBOSE_RESULTS

#include "porting_layer.h"

#include "math.h"

#ifdef TRACING
#define NO_TEST_ID NOBENCH_TEST_ID_COOP_SCHED
#endif

#define configUSE_PREEMPTION 1 	// for all tasks set to 0, for round_robin set to 1!!

#ifndef NB_ITER
#define NB_ITER 1000
#endif

#define NB_TASK 5 // 2

no_task_retval_t task(no_task_argument_t args);
no_task_retval_t round_robin_stress_initialize_test(no_task_argument_t args);

no_task_handle_t tasks_handle[NB_TASK];
char tasks_name[NB_TASK][5];

DECLARE_TIME_COUNTERS(no_time_t, _)

volatile int tasks_idx;
volatile int tasks_done_count;

int32_t results[NB_ITER];

no_main_retval_t main(no_main_argument_t args)
{
	no_initialize_test(round_robin_stress_initialize_test);
	return MAIN_DEFAULT_RETURN;
}

no_task_retval_t round_robin_stress_initialize_test(no_task_argument_t args)
{
	int32_t i;

	tasks_idx = 0;
	tasks_done_count = 0;

	for (i = 0 ; i < NB_TASK; i++)
	{
		tasks_name[i][0] = 65;
		tasks_name[i][1] = (65 + i) % 255;
		tasks_name[i][2] = (66 + i) % 255;
		tasks_name[i][3] = (67 + i) % 255;
		tasks_name[i][4] = '\0';
		tasks_handle[i] = no_create_task(task, tasks_name[i], BASE_PRIO);
	}
}

no_task_retval_t task(no_task_argument_t args)
{
	int32_t i;
	int32_t local_idx;

	/*
	 * A task pool is created and each one has a specific memory stack
	 * allocated for every purpose. Each task also has its own "copy" of the code
	 * When a task enters the first part it increments the tasks_idx and 
	 * gets a unique ID. Unique because tasks_idx is "volatile" (shared variable
	 * in a multitasking application) 
	 * Only task 0 and task 1 count t1 and t2. If there are more tasks they just 
	 * switch context.
	 */
	local_idx = tasks_idx++;
	if (local_idx == 0)
	{
		DECLARE_TIME_STATS(int32_t)
		for (i = 0; i < NB_ITER; i++)
		{
			//DO_WORKLOAD(i)
			/*
			 * #define WRITE_T1_COUNTER(SUFFIX) \
			 * t1 = time_get();
			 * 
			 * so actually get time and save to t1
			 * IMPORTANT: t1 is saved "locally": in the memory
			 * stack of the task, and it is not global.
			 */
			WRITE_T1_COUNTER(_)
			/*
			 * taskYIELD() is used to request a context switch
			 * to another task. However, if there are no other
			 * tasks at a higher or equal priority to the task
			 * that calls taskYIELD() then the RTOS scheduler
			 * will simply select the task that called
			 * taskYIELD() to run again.
			 * 
			 * So execution below is like:
			 * no_task_yield() ->  taskYIELD() -> portYIELD() -> asm code
			 */
			no_task_yield(); 
			/* 
			 * If there is a task with greater priority
			 * then execution pauses here and another task
			 * continues.
			 * After some cycles passes by this task gets 
			 * top priority again then execution is continued
			 * from here again and we calculate the t2-t1
			 */
			if (i > 0) 
			{
				/* 
				 * the check is for the first iteration, to ensure 
				 * that some time has passed by.
				 * one iteration is really fast compared to two or more
				 * or even context switch. 
				 * time_diff(t1, t2)
				 */
				COMPUTE_TIME_STATS(_, i);
			}
		}
		/*for (i = 0; i < NB_ITER; i++)
		{
			printf("%ld\n", results[i]);
			no_single_result_report("i=", results[i]);
		}*/
		no_serial_write("R");
		REPORT_BENCHMARK_RESULTS("-- cooperating scheduling ctx switch --")
	}
	else if (local_idx == 1)
	{
		for (i = 0; i < NB_ITER; i++)
		{
			//DO_WORKLOAD(i)
			no_serial_write("2");
			no_task_yield();
			/*
			 * #define WRITE_T2_COUNTER(SUFFIX) \
			 * t2 = time_get();
			 * 
			 * basically here, we compute t2 (time passed after t1 was calculated)
			 * and we continue to 
			 */
			WRITE_T2_COUNTER(_)
		}
	}
	else
	{
		for (i = 0; i < NB_ITER; i++)
		{
			//DO_WORKLOAD(i)
			no_task_yield();
		}
	}

	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}
