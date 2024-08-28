#!/bin/bash

echo -n "Insert first number: "
read n1
echo -n "Insert seceond number: "
read n2
let s=n1+n2
let p=n1*n2
echo "The sum is ${s}."
echo "The product is ${p}."

exit 0
