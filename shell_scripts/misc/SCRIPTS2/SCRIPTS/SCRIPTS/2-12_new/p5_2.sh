#!/bin/bash

# 5 5 5 5 5
# 4 4 4 4
# 3 3 3
# 2 2
# 1

for ((i=5;i>0;i--))
do
	for((j=i;j>0;j--))
	do
	echo -n "$i "
	done
	echo ""
done	
