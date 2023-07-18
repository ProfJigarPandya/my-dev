#!/bin/bash
#For pattern 5 1

echo "Enter n"
read n
for ((i=i;i<=n;i++))
do
	for((j=n;j>=i;j--))
	do
		echo -n "$j "
	done
	echo
done

