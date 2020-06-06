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
	@echo "   make EXAMPLE=<example> <test>"
	@echo ""
	@echo "possible examples = "
	@echo "   {"
	@echo "       linux, freertos-rpi2"
	@echo "   }"
	@echo "possible tests = "
	@echo "   {"
	@echo "       interrupt_processing, event, event_processing,"
	@echo "       mq, mq_workload, mq_processing, mutex, mutex_pip, mutex_workload,"
	@echo "       mutex_processing, sched_latency, sem, sem_processing,"
	@echo "       sem_prio, jitter"
	@echo "   }"
	@echo ""
	@echo "To clean:"
	@echo "   make clean"

clean:
	bash scripts/clean_script.sh
	# make -C example/$(EXAMPLE) clean

# interrupt_processing:
# 	@make -C example/$(EXAMPLE) NO_TEST_SRC=interrupt_processing.c NO_TEST_PATH=tests/interrupt NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
# 	mv example/$(EXAMPLE)/interrupt_processing example/$(EXAMPLE)/interrupt_processing_folder/

mq:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mq.c NO_TEST_PATH=tests/mq NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mq example/$(EXAMPLE)/mq_folder/

mq_workload:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mq_workload.c NO_TEST_PATH=tests/mq NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mq_workload example/$(EXAMPLE)/mq_workload_folder/

mq_processing:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mq_processing.c NO_TEST_PATH=tests/mq NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mq_processing example/$(EXAMPLE)/mq_processing_folder/

mutex:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mutex.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mutex example/$(EXAMPLE)/mutex_folder/

mutex_pip:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mutex_pip.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mutex_pip example/$(EXAMPLE)/mutex_pip_folder/

mutex_workload:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mutex_workload.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mutex_workload example/$(EXAMPLE)/mutex_workload_folder/

mutex_processing:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=mutex_processing.c NO_TEST_PATH=tests/mutex NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/mutex_processing example/$(EXAMPLE)/mutex_processing_folder/

# sched_latency:
# 	@make -C example/$(EXAMPLE) NO_TEST_SRC=sched_latency.c NO_TEST_PATH=tests/latency NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
# 	mv example/$(EXAMPLE)/sched_latency example/$(EXAMPLE)/sched_latency_folder/

sem:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=sem.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/sem example/$(EXAMPLE)/sem_folder/

sem_processing:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=sem_processing.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/sem_processing example/$(EXAMPLE)/sem_processing_folder/

sem_prio:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=sem_prio.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/sem_prio example/$(EXAMPLE)/sem_prio_folder/

sem_workload:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=sem_workload.c NO_TEST_PATH=tests/semaphore NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/sem_workload example/$(EXAMPLE)/sem_workload_folder/

jitter:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=jitter.c NO_TEST_PATH=tests/partition NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/jitter example/$(EXAMPLE)/jitter_folder/

round_robin:
	@make -C example/$(EXAMPLE) NO_TEST_SRC=round_robin.c NO_TEST_PATH=tests/context-switch NO_NB_ITER=$(NB_ITER) NOBENCH_TRACING=$(TRACING) NO_BASE_PRIO=$(BASE_PRIO) NO_AFFINITY=$(AFFINITY)
	mv example/$(EXAMPLE)/round_robin example/$(EXAMPLE)/round_robin_folder/

