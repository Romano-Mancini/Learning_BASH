#!/bin/bash

a=3
b=4
c=5

k=0
s=0

for i in $(cat $1)
do
	if [ $k -eq 0 ]
	then
		let s=${i}*${i}*${a}
		let k=${k}+1
	elif [ $k -eq 1 ]
	then
		let s=${s}+${i}*${b}
		let k=${k}+1
	elif [ $k -eq 2 ]
	then
		let s=${s}+${i}*${c}
		k=0
		echo "$s"
		s=0
	fi
done

exit 0
