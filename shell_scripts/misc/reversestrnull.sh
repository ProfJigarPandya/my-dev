#!/bin/bash
echo "Enter input"
read input
while [ ! -z "$input" ]
do
	echo -n `expr "$input" : '.*\(.\)'`
	#echo -e `expr "$input" : '.*\(.\)'`"\c"
	input=`expr "$input" : '\(.*\).'`
	#echo -e "\n$input"
done
