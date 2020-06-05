#!/bin/bash



targets=(
 "mq"
 "mutex"
 "sem"
 "round_robin"
  )

rm *.png
rm README.md
touch README.md
python3 mixer.py

for i in "${targets[@]}"
do
	echo "# $i" >> README.md
	echo "![$i]($i.png)" >> README.md
	echo "" >> README.md
done
