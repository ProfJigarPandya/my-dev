#!/bin/bash

# 1
# 1 2 
# 1 2 3
# 1 2 3 4
# 1 2 3 4 5

for ((i=1;i<=5;i++))
do
	for ((j=1;j<=i;j++))
	do
	echo -n "$j "
	done	
        echo  " "
done
