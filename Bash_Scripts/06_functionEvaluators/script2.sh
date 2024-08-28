#!/bin/bash

a=3
b=4
c=5

while read x y z
do
	let s=$a*$x*$x+$b*$y+$c*z
	echo "$s"
done < $1

exit 0
