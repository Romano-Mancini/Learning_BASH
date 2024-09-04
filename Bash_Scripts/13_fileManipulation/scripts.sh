#!/bin/bash

if [ $# -lt 1 ]
then
	echo "Not enough arguments."
	exit 1
elif [ $# -gt 1 ]
then
	echo "Too many arguments."
	exit 2
fi

cp "$1" "$(basename $1 ".txt").xyz"

n=0
while read line
do
	i=0
	let n=n+1
	for string in $line
	do
		let i=i+1
	done
	echo "$i - $line" 
done < $1 > "/tmp/$$.txt"

cat "/tmp/$$.txt" | sort -k 1n,1n > $1

echo "Total number of lines: ${n}." >> $1

exit 0
