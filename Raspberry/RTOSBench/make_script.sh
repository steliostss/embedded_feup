#!/bin/bash

# if you want round robin, you must edit FreeRtosConfig file and set PREEMPTION to 0
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

#rm -rf eample/kernel/tests
mkdir example/linux/kernel_tests/

for i in "${targets[@]}"
do
  echo $i
  make clean
  make $i "EXAMPLE=linux"
  rm -rf example/linux/kernel_tests/$i/
  mkdir example/linux/kernel_tests/$i/
  # cp example/freertos-rpi2/kernel7.img example/freertos-rpi2/kernel_tests/$i/
  echo "done"
done
