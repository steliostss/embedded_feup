#!/bin/bash



targets=(
 "mq"
 "mutex"
 "sem"
 "round_robin"
  )

touch README.md
python mixer.py

for i in "${targets[@]}"
do
	echo $i >> README.md
	echo "![$i]($i.png)" >> README.md
done