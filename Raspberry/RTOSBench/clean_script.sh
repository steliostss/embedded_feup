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

cd example/linux
rm -rf bld/

for i in "${targets[@]}"
do
  echo "Cleaning $i"
  cd $i"_folder"
  rm $i
  cd ..
done
