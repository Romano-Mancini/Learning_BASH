#!/bin/bash

echo -n "Insert a string: "

read str
output=$(echo $str | wc -c)
let output=$output-1 # remove the '\0' from the total

echo "The string \"$str\" is $output characters long."

exit 0
