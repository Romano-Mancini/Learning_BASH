#!/bin/bash

if [ $# -lt 1 ]
then
	echo "No files were provided."
	exit 1
fi

for file in $*
do
	if [ -f $file ]
	then
		echo "Name: $file."
		echo "Dimension: $(cat $file | wc -c)."
		
		if [ -r $file ]
		then
			echo "The user has read permissions."
		else
			echo "The user does not have read permissions."
		fi
		
		if [ -w $file ]
		then
			echo "The user has write permissions."
		else
			echo "The user does not have write permissions."
		fi
		
	elif [ -d $file ]
	then
		echo "Name: $file."
		nSub=$(ls -l $file | grep -E -e "^d" | wc -l)
		let nSub=nSub-2
		echo "Number of subdirectories: $nSub."
	fi
	
	echo "----"
done

exit 0
