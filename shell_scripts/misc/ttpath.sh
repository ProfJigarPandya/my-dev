#!/bin/bash
#Display each component of $PATH 
IFS=:
set $PATH
for((i=1;i<=$#;i++))
do
	echo "${!i}"
done

