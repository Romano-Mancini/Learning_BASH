#!/bin/bash

if [ $# -ne 6 ]
then
	echo "Correct use: ./script.sh fileIn str1 str2 N str3 fileOut."
	exit 1
fi

while read line
do
	for i in $(seq 0 $4)
	do
		echo -n "$5 "
	done
	
	for word in $line
	do
		if [ "$word" = "$2" ]
		then
			echo -n "$3 "
		else
			echo -n "$word "
		fi
	done
	
	for i in $(seq 0 $4)
	do
		echo -n "$5 "
	done
	
	echo ""
done < $1 > $6

exit 0
