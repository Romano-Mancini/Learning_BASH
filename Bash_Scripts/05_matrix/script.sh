#!/bin/bash

if [ $# -lt 2 ]
then
	echo "Insert n1: "
	read n1
	echo "Insert n2: "
	read n2	
else 
	n1=$1
	n2=$2
fi

let p=${n1}*${n2}-1

for i in $(seq 0 $p)
do
	let m=${i}%${n2}
	if [ $m -eq 0 ]
	then
		echo ""
	fi
	echo -n "$i "
done

echo ""

exit 0
