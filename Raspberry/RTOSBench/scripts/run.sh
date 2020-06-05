#!/bin/bash

# if you want round robin, you must edit FreeRtosConfig file and set PREEMPTION to 0
targets=(
  # "interrupt_processing"
#  "mq"
#  "mq_workload"
#  "mq_processing"
#  "mutex"
#  "mutex_pip"
#  "mutex_workload"
#  "mutex_processing"
#	"sem"
#	"sem_processing"
#	"sem_prio"
	"sem_workload"
	# "jitter"
  # "round_robin"
  )

for i in "${targets[@]}"
do
  for k in 1 2 3 4 5 
  do
    echo "Test: "$i", attempt "$k
    echo "execution started"
    sudo bash begin_test.sh $i
    echo "execution finished"
    echo "-------------------------------------------"
  done
done
