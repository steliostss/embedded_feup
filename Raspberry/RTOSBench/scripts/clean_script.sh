#!/bin/bash

targets=(
	"interrupt_processing"
	"mq"
	"mq_workload"
	"mutex"
	"mutex_pip"
	"mutex_workload"
	"mutex_processing"
	"sem"
	"sem_processing"
	"sem_prio"
	"jitter")

cd ../example/linux
rm -rf bld/

for i in "${targets[@]}"
do
	echo "Cleaning $i"
	cd $i"_folder"
	rm $i
	cd ..
done
