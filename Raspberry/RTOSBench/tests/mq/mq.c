/* Copyright (c) 2019, Guillaume Champagne
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "porting_layer.h"

#ifdef TRACING
#define NO_TEST_ID NOBENCH_TEST_ID_MQ_SIGNAL
#endif

#ifndef NB_ITER
#define NB_ITER 1000000
#endif

no_task_retval_t mq_initialize_test(no_task_argument_t args);
no_task_retval_t sender(no_task_argument_t args);
no_task_retval_t receiver(no_task_argument_t args);

no_task_handle_t tasks_handle[2];
no_mq_t mq;

DECLARE_TIME_COUNTERS(no_time_t, s_to_r) // send to receive
DECLARE_TIME_COUNTERS(no_time_t, r_to_s) // receive to send

no_main_retval_t main(no_main_argument_t args)
{
	/*
	 * This function
	 */
	no_initialize_test(mq_initialize_test);
	return MAIN_DEFAULT_RETURN;
}

no_task_retval_t mq_initialize_test(no_task_argument_t args)
{
	/* 
	 * Create resources:
	 * create a queue of 2 positions
	 */
	no_mq_create(&mq, 2, sizeof(int32_t));

	// define sender as a task
	tasks_handle[0] = no_create_task(sender,
			"S",
			BASE_PRIO - 1 /* sender is the low priority task. */
		);

	// define receiver as a task
	tasks_handle[1] = no_create_task(receiver,
			"R",
			BASE_PRIO /* receiver is the high priority task. */
		);

	return TASK_DEFAULT_RETURN;
}

no_task_retval_t sender(no_task_argument_t args)
{
	int32_t i;

	/* 2b - Benchmark. */
	for (i = 0; i < NB_ITER + 1; i++)
	{	
		/* 
		 * Send to receiver 1 byte.
		 * Receiver initiates t1 variable and then sender calculates t2.
		 * This way we count the time it took for a message to be received,
		 * but without taking into consideration the sending time. 
		 */
		no_mq_send(&mq, 1);
		WRITE_T2_COUNTER(r_to_s)
	}

	for (i = 0; i < NB_ITER; i++)
	{
		/* 
		 * Send to receiver 1 byte.
		 * Receiver initiates t1 variable and then sender calculates t2.
		 * This way we count the time it took for a message to be received,
		 * but we also take into consideration the sending time. 
		 */
		WRITE_T1_COUNTER(s_to_r)
		no_mq_send(&mq, 1);
	}

	// finish task
	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}

no_task_retval_t receiver(no_task_argument_t args)
{
	int32_t i;
	DECLARE_TIME_STATS(int64_t)

	/* 1 - Let sender start */
	no_mq_receive(&mq);

	/* 2a - Benchmark. */
	for (i = 0; i < NB_ITER; i++)
	{
		/* 
		 * Receive the message.
		 * Firstly initialize t1, so we only count the transfer time. 
		 * Then print the results.
		 * send() -> count() -> transfer -> count() -> receive()
		 */
		WRITE_T1_COUNTER(r_to_s)
		no_mq_receive(&mq);
		COMPUTE_TIME_STATS(r_to_s, i);
#ifndef TRACING
		no_cycle_reset_counter();
#endif
	}

	REPORT_BENCHMARK_RESULTS("-- MQ: Receive block --")
	RESET_TIME_STATS()

	for (i = 0; i < NB_ITER; i++)
	{
		/* 
		 * Receive the message.
		 * This way we count the total amount of time to send and receive.
		 * count() -> send() -> transfer -> receive() -> count()
		 */		
		no_mq_receive(&mq);
		WRITE_T2_COUNTER(s_to_r)
		COMPUTE_TIME_STATS(s_to_r, i)
#ifndef TRACING
		no_cycle_reset_counter();
#endif
	}

	REPORT_BENCHMARK_RESULTS("-- MQ: Signal unblock --")

	no_task_suspend_self();

	return TASK_DEFAULT_RETURN;
}


/*
 * General comments:
 * 	For a send-receive function to execute we have to follow these steps:
 * 	1. 	Initialize receiver and "put up a notice": "READY_TO_RECEIVE" 
 * 		(this is why t1 counter is initialized in receiver and not in sender)
 * 	2. 	Initialize sender and send the message. Sender must always have an open
 * 		slot from someone to receive him message.
 */