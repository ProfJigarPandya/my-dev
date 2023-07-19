#!/bin/bash
# 1
# 2 2
# 3 3 3
# 4 4 4 4
# 5 5 5 5 5

for ((i=1;i<=5;i++))
do
	for ((j=1;j<=i;j++))
	do
	echo -n "$i"
	done
	echo  " "
done
