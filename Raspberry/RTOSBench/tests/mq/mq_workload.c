/* Copyright (c) 2019, Guillaume Champagne
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "porting_layer.h"

#ifdef TRACING
#define NO_TEST_ID NOBENCH_TEST_ID_MQ_SIGNAL_WORK
#endif

#ifndef NB_ITER
#define NB_ITER 7000
#endif

#ifndef NB_WORKLOAD_TASK
#define NB_WORKLOAD_TASK 50
#endif

#ifndef DELAY_MS
#define DELAY_MS 10
#endif

no_task_retval_t mq_initialize_test(no_task_argument_t args);
no_task_retval_t sender(no_task_argument_t args);
no_task_retval_t receiver(no_task_argument_t args);
no_task_retval_t workload_task(no_task_argument_t args);

no_task_handle_t tasks_handle[2];
no_task_handle_t workload_tasks_handle[NB_WORKLOAD_TASK];
char workload_tasks_name[NB_WORKLOAD_TASK][4];

no_mq_t mq;

DECLARE_TIME_COUNTERS(no_time_t, _)

no_main_retval_t main(no_main_argument_t args)
{
	no_initialize_test(mq_initialize_test);
	return MAIN_DEFAULT_RETURN;
}

no_task_retval_t mq_initialize_test(no_task_argument_t args)
{
	int32_t i;

	/* Create resources */
	no_mq_create(&mq, 2, sizeof(int32_t));

	tasks_handle[0] = no_create_task(sender,
			"S",
			BASE_PRIO - 1 /* sender is the low priority task. */
		);

	tasks_handle[1] = no_create_task(receiver,
			"R",
			BASE_PRIO /* receiver is the high priority task. */
		);

	for (i < 0 ; i < NB_WORKLOAD_TASK; i++)
	{
		workload_tasks_name[i][0] = 65;
		workload_tasks_name[i][1] = (65 + i) % 255;
		workload_tasks_name[i][2] = 0;
		workload_tasks_name[i][3] = 0;
		/* Workoad tasks are the lowest priority */
		workload_tasks_handle[i] = no_create_task(workload_task, workload_tasks_name[i], BASE_PRIO - 2);
	}

	return TASK_DEFAULT_RETURN;
}

no_task_retval_t sender(no_task_argument_t args)
{
	int32_t i;

	/* 2b - Benchmark. */
	for (i = 0; i < NB_ITER + 1; i++)
	{
		WRITE_T1_COUNTER(_)
		no_mq_send(&mq, 1);
		no_task_delay(DELAY_MS);
	}s

	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}

no_task_retval_t receiver(no_task_argument_t args)
{
	int32_t i;
	DECLARE_TIME_STATS(int64_t)

	/* 2a - Benchmark. */
	for (i = 0; i < NB_ITER; i++)
	{
		no_mq_receive(&mq);
		WRITE_T2_COUNTER(_)
		COMPUTE_TIME_STATS(_, i);
#ifndef TRACING
		no_cycle_reset_counter();
#endif
	}

	REPORT_BENCHMARK_RESULTS("-- MQ workload --")

	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}

no_task_retval_t workload_task(no_task_argument_t args)
{
	int32_t i;
	unsigned long _workload_results[100];

	while (1)
	{
		DO_WORKLOAD(i % 100)
		no_task_yield();
		i++;
	}

	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}

/*
 * First check "mq.c" explanation comments.
 * In this file, code flow is similar to "mq.c" with the only
 * difference there are some more tasks that are in a for loop
 * and have some workload: DO_WORKLOAD(i%100)
 * After this workload, context switch is attempted.
 * Again, only one task is sender and one receiver.
 */

