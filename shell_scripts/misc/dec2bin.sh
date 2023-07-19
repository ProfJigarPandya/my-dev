#!/bin/bash
echo "Enter decimal number"
read n
result=''
while [ $n -gt 0 ]
do
	mod=`expr $n % 2`
	n=`expr $n / 2`
	result=`echo -n "$result$mod"`
done
echo $result

