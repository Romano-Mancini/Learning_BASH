#!/bin/bash

echo -n "Is it morning (yes/no)? "
read ans
if [ "${ans}" = "yes" ] 
then
	echo "Good morning!"
elif [ "${ans}" = "no" ]
then
	echo "Good afternoon!"
else
	echo "Invalid response!"
fi

exit 0
