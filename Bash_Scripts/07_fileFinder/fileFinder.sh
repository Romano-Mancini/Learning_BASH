#!/bin/bash

for i in $(find . -maxdepth 1 -name "*.c" )
do
	if [ $(grep "POSIX" $i | wc -w) -ge 1 ] 
	then
		echo "Content of file ${i}:"
		cat $i
		echo ""
	fi 
done

exit 0
