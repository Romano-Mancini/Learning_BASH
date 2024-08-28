#!/bin/bash

for i in $(cat $1)
do
	for k in $(seq 1 $i)
	do
		echo -n "*"
	done
	echo ""
done

exit 0
