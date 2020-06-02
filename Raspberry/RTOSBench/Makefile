ifndef EXAMPLE
EXAMPLE = linux
endif

ifndef NB_ITER
NB_ITER = 5000
endif

ifndef BASE_PRIO
BASE_PRIO = 10
endif

ifndef AFFINITY
AFFINITY = 2
endif

.PHONY: clean

nothing:
	@echo "Usage:" 
	@echo "    make EXAMPLE=<example> <test>"
	@echo ""
	@echo "possible examples = "
	@echo "    {linux, freertos-rpi2}"
	@echo "possible tests = "
	@echo "    {"
	@echo "     interrupt_processing, event, event_processing,"
	@echo "     mq, mq_workload, mutex, mutex_pip, mutex_workload,"
	@echo "     mutex_processing, sched_latency, sem, sem_processing,"
	@echo "     sem_prio, jitter}"
	@echo "    }"
	@echo ""
	@echo "To clean:"
	@echo "    make clean"
clean:
	bash clean_script.sh
	# make -C example/$(EXAMPLE) clean

interrupt_processing:
	@make -C example/$(EXAMPLE)/interrupt_processing_folder NO_TEST_SRC=interrupt_processing.c NO_TEST_PATH=tests/interrupt NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

event:
	@make -C example/$(EXAMPLE)/event_folder NO_TEST_SRC=event.c NO_TEST_PATH=tests/event NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

event_processing:
	@make -C example/$(EXAMPLE)/event_processing_folder NO_TEST_SRC=event_processing.c NO_TEST_PATH=tests/event NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mq:
	@make -C example/$(EXAMPLE)/mq_folder NO_TEST_SRC=mq.c NO_TEST_PATH=tests/mq NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mq_workload:
	@make -C example/$(EXAMPLE)/mq_workload_folder NO_TEST_SRC=mq_workload.c NO_TEST_PATH=tests/mq NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mq_processing:
	@make -C example/$(EXAMPLE)/mq_processing_folder NO_TEST_SRC=mq_processing.c NO_TEST_PATH=tests/mq NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mutex:
	@make -C example/$(EXAMPLE)/mutex_folder NO_TEST_SRC=mutex.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mutex_pip:
	@make -C example/$(EXAMPLE)/mutex_pip_folder NO_TEST_SRC=mutex_pip.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mutex_workload:
	@make -C example/$(EXAMPLE)/mutex_workload_folder NO_TEST_SRC=mutex_workload.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

mutex_processing:
	@make -C example/$(EXAMPLE)/mutex_processing_folder NO_TEST_SRC=mutex_processing.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

round_robin:
	@make -C example/$(EXAMPLE)/round_robinfolder NO_TEST_SRC=round_robin.c NO_TEST_PATH=tests/context-switch NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

sched_latency:
	@make -C example/$(EXAMPLE)/sched_latency_folder NO_TEST_SRC=sched_latency.c NO_TEST_PATH=tests/latency NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

sem:
	@make -C example/$(EXAMPLE)/sem_folder NO_TEST_SRC=sem.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

sem_processing:
	@make -C example/$(EXAMPLE)/sem_processing_folder NO_TEST_SRC=sem_processing.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

sem_prio:
	@make -C example/$(EXAMPLE)/sem_prio_folder NO_TEST_SRC=sem_prio.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

sem_workload:
	@make -C example/$(EXAMPLE)/sem_workload_folder NO_TEST_SRC=sem_workload.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

jitter:
	@make -C example/$(EXAMPLE)/jitter_folder NO_TEST_SRC=jitter.c NO_TEST_PATH=tests/partition NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)

