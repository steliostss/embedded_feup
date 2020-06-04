/* Copyright (c) 2019, Guillaume Champagne
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "porting_layer.h"

#ifdef TRACING
#define NO_TEST_ID NOBENCH_TEST_ID_INT_PROC
#endif

#ifndef NB_ITER
#define NB_ITER 12000
#endif

no_task_retval_t task1(no_task_argument_t args);
no_task_retval_t interrupt_initialize_test(no_task_argument_t args);
no_task_retval_t task(no_task_argument_t args);


no_task_handle_t tasks_handle;

DECLARE_TIME_COUNTERS(no_time_t, _)

NO_DECLARE_INT_HANDLER(swi_int_handler, _)

no_main_retval_t main(no_main_argument_t args)
{
	/*
	 * The function call below initializes the interrupt handler
	 * with all available interrupts (around 32 I think)
	 * and starts the test by creating one task that it's 
	 * execution is interrupted constantly while
	 * in a loop for (0, NB_ITER)
	 */
	no_initialize_test(interrupt_initialize_test);
	return MAIN_DEFAULT_RETURN;
}

no_task_retval_t interrupt_initialize_test(no_task_argument_t args)
{
	// A task that calculates t1 is created
	tasks_handle = no_create_task(task, "t1", BASE_PRIO);
	// Handlers are initialized
	no_interrupt_register_sgi_handler(swi_int_handler);
	// Handlers are enabled
	no_interrupt_enable_sgi(); //sgi = Soft Generated Interrupts
}

no_task_retval_t task(no_task_argument_t args)
{
	int32_t i;
	// declare min max average cycles
	DECLARE_TIME_STATS(int64_t)

#ifndef TRACING
		no_cycle_reset_counter();
#endif

	/* 1a - Start benchmark. */
	for (i = 0; i < NB_ITER; i++)
	{
		// counting time begins here
		WRITE_T1_COUNTER(_)
		// we interupt execution
		no_interrupt_do_sgi();
		// calculate t2 and print time stamps
		COMPUTE_TIME_STATS(_, i);
#ifndef TRACING
		no_cycle_reset_counter();
#endif
	}

	REPORT_BENCHMARK_RESULTS("-- interrupt processing --")

	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}
