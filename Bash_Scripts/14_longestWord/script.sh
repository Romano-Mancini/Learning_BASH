#!/bin/bash

longestWord=""
longestLength=0

if [ ! -f "file.txt" ]
then
	echo "There is not a file named file.txt."
	exit 1
fi

while read word
do
	lenght=$(echo "$word" | wc -m)
	if [ $lenght -gt $longestLength ]
	then
		longestLenght=$lenght
		longestWord=$word
	fi
done < "file.txt"

echo "The longest word in the file is $longestWord, with a total of $longestLenght characters."

exit 0
