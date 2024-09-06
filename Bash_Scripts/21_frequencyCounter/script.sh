#!/bin/bash

if [ $# -lt 1 ]
then
	echo -n "Insert the name of the input file: "
	read file
else
	file=$1
fi

declare -A array

for word in $(cat $file)
do
	echo ${!array[*]} | grep -q $word
	if [ $? -eq 0 ]
	then
		let array[$word]=${array[$word]}+1
	else
		array[$word]=1 
	fi 
done

for word in ${!array[*]}
do
	echo -e "${array[$word]} - $word"
done

exit 0
