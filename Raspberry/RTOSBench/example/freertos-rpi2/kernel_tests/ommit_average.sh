#!/bin/bash

targets=(
	 "mq"
	 "mq_workload"
	 "mq_processing"
	 "mutex"
	 "mutex_pip"
	 "mutex_workload"
	 "mutex_processing"
	 "sem"
	 "sem_processing"
	 "sem_prio"
 	 "round_robin"
 )

for i in "${targets[@]}"
do
	cd $i"/csv"
	for f in `ls *averaged.csv`
	do
		pwd
		echo $i &>> /mnt/Storage/Documents/ECE/Erasmus/porto/courses/embedded_feup/Raspberry/RTOSBench/example/freertos-rpi2/kernel_tests/averaged.csv
		cat $f &>> /mnt/Storage/Documents/ECE/Erasmus/porto/courses/embedded_feup/Raspberry/RTOSBench/example/freertos-rpi2/kernel_tests/averaged.csv
	done
	echo  &>> /mnt/Storage/Documents/ECE/Erasmus/porto/courses/embedded_feup/Raspberry/RTOSBench/example/freertos-rpi2/kernel_tests/averaged.csv

	cd ..
done
