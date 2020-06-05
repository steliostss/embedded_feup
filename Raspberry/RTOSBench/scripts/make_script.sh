#!/bin/bash

# if you want round robin, you must edit FreeRtosConfig file and set PREEMPTION to 0
# targets=(
# 	"interrupt_processing"
# 	"event"
# 	"event_processing"
# 	"mq"
# 	"mq_workload"
# 	"mq_processing"
# 	"mutex"
# 	"mutex_pip"
# 	"mutex_workload"
# 	"mutex_processing"
# 	"sem"
# 	"sem_processing"
# 	"sem_prio"
	"sem_workload"
# 	"jitter")

#rm -rf eample/kernel/tests
#mkdir example/linux/kernel_tests/

# if you want to make freertos-rpi2 change variable name below
# example="linux"
# example="freertos-rpi2
# cd example/$example/
# echo ""
# pwd
# echo ""
# mkdir kernel_tests


# for i in "${targets[@]}"
# do
#   echo $i
# #  make clean
#   make EXAMPLE=linux $i
#   # cp example/freertos-rpi2/kernel7.img example/freertos-rpi2/kernel_tests/$i/
#   echo "done"
# done

# echo "This script does not work."
echo "type \"make\" on RTOSBench/ directory to see how to compile individual tests."

cd ..

make EXAMPLE=linux interrupt_processing
make EXAMPLE=linux mq
make EXAMPLE=linux mq_workload
make EXAMPLE=linux mq_processing
make EXAMPLE=linux mutex
make EXAMPLE=linux mutex_pip
make EXAMPLE=linux mutex_workload
make EXAMPLE=linux mutex_processing
make EXAMPLE=linux sem
make EXAMPLE=linux sem_processing
make EXAMPLE=linux sem_prio
make EXAMPLE=linux sem_workload
make EXAMPLE=linux jitter
make EXAMPLE=linux round_robin
