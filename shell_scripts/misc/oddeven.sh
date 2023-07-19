#!/bin/bash
#Assumption is that input is a valid number
echo 'Enter input for checking odd or even'
read input

modulo=`expr $input % 2`
echo $modulo
if [ $modulo -eq 1 ]
then
	echo "Input number $input is a odd number"
else
	echo "Input number $input is an even number"
fi

