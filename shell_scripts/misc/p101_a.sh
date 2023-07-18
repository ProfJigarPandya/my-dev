#!/bin/bash
# Develop a shell script to generate series 1 0 1 0 1 0 1 0  1 ... for number of terms entered by user as input. Here, each digit is a term of series. 
# For example if user enters 8 then  output shall be 1 0 1 0 1 0 1 0    
echo "Enter number of terms to be displayed for the series"
read n
for ((i=1;i<n;i++))
do
	echo -n `expr $i % 2`" "
done
echo -n `expr $n % 2`
