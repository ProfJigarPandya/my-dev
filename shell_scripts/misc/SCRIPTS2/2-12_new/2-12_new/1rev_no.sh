#!/bin/bash

n=$1
rev=0
s=0

while [ $n -gt 0 ]
do
    s=`expr $n % 10`
    rev=`expr $rev \* 10  + $s`
    n=`expr $n / 10`
done
 echo  "Reverse number is $rev"
