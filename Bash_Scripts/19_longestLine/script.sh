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

nLongLine=0

while read line
do
	length=$(echo -n $line | wc -m)
	if [ $length -gt $nLongLine ]
	then
		nLongLine=$length
	fi
done < $1

echo "The longest line is $nLongLine characters long."
echo "The file is $(cat $1 | wc -l) lines long."

exit 0
