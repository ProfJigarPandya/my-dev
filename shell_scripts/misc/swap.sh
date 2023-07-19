#!/bin/bash
# Shell script to swap two numbers

#echo 'Enter two numbers separated by whitespace'
#read n1 n2
echo 'Enter n1'
read n1
echo 'Enter n2'
read n2

#if [ -z "$n1" ] || [ -z "$n2" ];
if [ -z "$n1" -o -z "$n2" ];
then
	echo "Either n1 or n2 is not read properly";
	exit 1 #Failure
else
	echo 'You entered n1 as '$n1' and n2 as '$n2
	buffer=$n1
	n1=$n2
	n2=$buffer
	echo 'After swaping now n1 is '$n1' and n2 is '$n2
	exit 0 # Success
fi
