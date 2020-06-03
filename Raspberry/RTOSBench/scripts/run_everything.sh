#!/bin/bash

# if you want round robin, you must edit FreeRtosConfig file and set PREEMPTION to 0
targets=(
#	"interrupt_processing"
#	"event"
#	"event_processing"
#	"mq"
#	"mq_workload"
#	"mutex"
#	"mutex_pip"
#	"mutex_workload"
#	"mutex_processing"
#	"sched_latency"
	"sem"
	"sem_processing"
	"sem_prio"
	"jitter")

cd example/linux/

for i in "${targets[@]}"
do
  echo $i
  cd $i"_folder"
  sudo ./$i &> $i.txt
  echo &>> $i.txt
  echo "-----------------------new execution----------------------" >> $i.txt
  echo &>> $i.txt
  sudo ./$i &>> $i.txt
  echo &>> $i.txt
  echo "-----------------------new execution----------------------" >> $i.txt
  echo &>> $i.txt
  sudo ./$i &>> $i.txt
  echo "done"
  echo &>> $i.txt
  cd ..
done
