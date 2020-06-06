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
	"jitter"
	"round_robin")

cd ../example/linux
rm -rf bld/

for i in "${targets[@]}"
do
	echo "Cleaning $i"
	cd $i"_folder"
	rm $i
	cd ..
done
