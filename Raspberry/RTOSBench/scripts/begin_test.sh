#!/bin/bash

cd ../example/linux/

i=$1
cd $i"_folder"
echo "-----------------------"$i" new execution----------------------" >> $i.txt
echo "begin"
timeout 2m sudo ./$i &>> $i.txt
echo &>> $i.txt
echo "finish"
