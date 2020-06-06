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
	"sem_workload"
	# "round_robin"
	"jitter")

# cd ../example/linux/
cd ../example/freertos-rpi2/kernel_tests

for i in "${targets[@]}"
do
#	mv $i executables/
#	mkdir $i
#	mv $i.txt $i/
	cd $i
	mkdir csv
	mkdir png
	mv *.csv csv/
	mv *.png png/
	cd ..
done