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

while read line
do
	nWords=$(echo $line | wc -w)
	let rem=$nWords%2
	if [ $rem -eq 0 ]
	then
		for word in $line
		do
			echo -n "$(echo -n $word | tr "[a-z]" "[A-Z]") " 
		done
	else
		for word in $line
		do
			echo -n "$(echo -n $word | tr "[A-Z]" "[a-z]") " 
		done
	fi
	echo ""
done < $1 > "/tmp/$$"

cat "/tmp/$$" > $1

cat $1

exit 0
