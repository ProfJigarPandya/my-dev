#!/bin/bash
# 2nd form------ if-then-else-fi statement
#example of comparing two numbers for equality
#
echo -e "Enter a number \c"
read no1
echo -e "Enter another number \c"
read no2
if [ $no1 -eq $no2 ];
then
	echo "Both numbers are equal "
else
	echo "Both numbers are not equal"
fi
echo "Have a nice day."

