#!/bin/bash
#Shell script to reverse a number
echo "Enter a number to be reversed";
read n
$res
len=`expr $n : '.*'`

if [ $len -eq 1 ]
then
	echo "Reversed number is $n"
else
	modulo=`expr $n % 10`
	res=$modulo
	n=`expr $n / 10`

	while [ $n -gt 0 ]
	do
		modulo=`expr $n % 10`
		n=`expr $n / 10`
		res=`expr $res \* 10 + $modulo`
	done
	echo "Reversed number is $res"
fi

echo "Have a nice day!"
