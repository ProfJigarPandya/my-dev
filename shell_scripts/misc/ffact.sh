#!/bin/sh
# Program for finding factorial on n using function.
fac()
{
	if [ "$1" -gt 1 ]; then
		result=1
		for ((i=1;i<="$1";i++))
		do
			result=`expr $result \* $i`
		done
		echo $result
	else
		echo 1
	fi
}

echo "Enter a number: "
read NUM
echo "$NUM! = `fac $NUM`"
