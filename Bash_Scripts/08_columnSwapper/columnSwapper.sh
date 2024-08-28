#!/bin/bash

n=0

while read c1 c2
do
	vett1[$n]=$c1
	vett2[$n]=$c2
	let n=n+1
done < $1

let n=n-1

for i in $(seq 0 $n)
do
	echo "${vett2[$i]} ${vett1[$i]}"
done > $1

exit 0
