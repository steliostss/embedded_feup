#!/bin/bash

targets=(
	"interrupt_processing"
	"event"
	"event_processing"
	"mq"
	"mq_workload"
	"mutex"
	"mutex_pip"
	"mutex_workload"
	"mutex_processing"
	"sched_latency"
	"sem"
	"sem_processing"
	"sem_prio"
	"jitter")

cd example/linux/

cd i

for i in "${targets[@]}"
do
#	mv $i executables/
#	mkdir $i
#	mv $i.txt $i/
	mv $i ../$i/
done
