#!/bin/bash

num=1
i=0

while [ "$num" -ne 0 ]
do
	echo -n "Insert number: "
	read num
	arr[$i]=$num
	let i=i+1
done

while [ "$i" -ge 0 ] 
do
	echo -n "${arr[$i]} "
	let i=i-1
done

exit 0
