#!/bin/bash
# Reversing a string using expr

echo "Enter String"
read str

if [ -z $str ]
then
	echo "No input. Try again later."
	exit 1
else
	echo "You entered $str"
	len=`expr $str : ".*"`

	echo -e "Reversed string is \c"
	for(( count=0; count<$len ; count++))
	do
		echo -e `expr "$str" : '.*\(.\)'`"\c"
		str=`expr "$str" : '\(.*\).'`
	done
	echo
fi
echo "Have a nice day."
exit 0
