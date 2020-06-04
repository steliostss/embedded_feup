#!/bin/bash

# if you want round robin, you must edit FreeRtosConfig file and set PREEMPTION to 0ll
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

rm README.md
rm allstats.csv

touch README.md
touch allstats.csv

echo "# Results Raspberry"

for i in "${targets[@]}"
do
    #echo "## $i" >> README.md
    cd $i
    echo "Taking output: "$i
    echo "parsing started"
    python3 ../parser.py $i
    touch README.md
    echo "# $i" > README.md
    echo "## $i" >> ../README.md
    echo "$i" >> ../allstats.csv
    echo "![$i]($i.png)" >> README.md
    echo "![$i]($i.png)" >> ../README.md
    echo "" >> README.md
    echo "" >> ../README.md
    /home/alena/.local/bin/csv2md stats.csv >> README.md
    /home/alena/.local/bin/csv2md stats.csv >> ../README.md
    echo " " >> ../README.md
    cat stats.csv >> ../allstats.csv
    echo "--------" >> ../allstats.csv
    echo "parsing finished"
    echo "-------------------------------------------"
    cd ../
done
