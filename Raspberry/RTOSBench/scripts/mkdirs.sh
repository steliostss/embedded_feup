#!/bin/bash

targets=(
	# "mq"
	"mq_processing"
	"mq_workload"
	"mutex"
	"mutex_pip"
	"mutex_processing"
	"mutex_workload"
	"round_robin"
	"sem"
	"sem_prio"
	"sem_processing"
	"sem_workload"
	# "jitter"
	)

cd ../example/linux/
# cd ../example/freertos-rpi2/kernel_tests

for i in "${targets[@]}"
do
#	mv $i executables/
#	mkdir $i
#	mv $i.txt $i/
	cd $i"_folder"
	# cd $i
	mkdir csv
	mkdir png
	mv *.csv csv/
	mv *.png png/
	cd ..
done