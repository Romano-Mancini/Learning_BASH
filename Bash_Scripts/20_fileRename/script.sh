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

for file in $(echo $(find $1))
do
	mv "$1/$file" "$1/$(echo $file | tr "[A-Z]" "[a-z]")" 
done

exit 0
