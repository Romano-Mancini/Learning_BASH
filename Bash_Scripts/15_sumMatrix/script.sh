#!/bin/bash

if [ $# -lt 1 ]
then
	echo "Not enough arguments."
	exit 1
elif [ $# -gt 1 ]
then
	echo "Too many arguments."
	exit 2
elif [ ! -f $1 ]
then
	echo "$1 is not a file."
	exit 3
fi

rows=$(cat $1 | wc -l)
i=0
toPrint=0
tot=0

for word in $(cat $1)
do
	let i=$i%$rows
	if [ $i -eq $toPrint ]
	then
		let tot=$tot+$(echo -n $word | wc -m)
		let toPrint=$toPrint+1
	fi
	let i=$i+1
done

echo "Result: $tot."

exit 0
