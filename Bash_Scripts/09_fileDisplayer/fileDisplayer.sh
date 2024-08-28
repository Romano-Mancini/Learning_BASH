#!/bin/bash

n=1

while read line
do
	echo "$n - $line"
	let n=n+1 
done < $1
echo "-----------"


n=1

for i in $(cat $1)
do
	echo "$n - $i"
	let n=n+1
done

exit 0
