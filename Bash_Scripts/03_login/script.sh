#!/bin/bash

echo -n "Insert username: "
read username
output=$(who | grep $username | wc -l)
echo "The user $username has logged in $output times."

exit 0
