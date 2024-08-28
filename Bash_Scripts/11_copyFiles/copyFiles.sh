#!/bin/bash

if [ ! -e $1 -o ! -d $1 ]
then
	mkdir $1
fi

for i in $*
do
	if [ $i = $1 ]
	then
		continue
	fi
	
	ans="def"
	while [ "$ans" != "Y" -a "$ans" != "N" ]
	do
		echo "Copy ${i} (Y/N)? "
		read ans
		if [ "$ans" = "Y" ]
		then
			cp ${i} "./${1}/${i}"
		elif [ "$ans" = "N" ]
		then
			:
		else
			echo "Invalid answer."
		fi
	done
done

exit 0
