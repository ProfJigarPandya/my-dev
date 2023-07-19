#!/bin/bash

n=$1
sum=0
last=0
while [ $n -gt 0 ]
do
    last=`expr $n % 10`
    sum=`expr $sum + $last`
    n=`expr $n / 10`
done
    echo  "Sum of digit for numner is $sum"
