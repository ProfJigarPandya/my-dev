#!/bin/bash
#where to use shift command?
echo "Program to learn shift "
while  test $1  ;
do
	if [ "$1" = "-b" ]
	then
		ob=$2
	case $ob in
		16) basesystem="Hex";;
		8) basesystem="Oct";;
		2) basesystem="Bin";;
		*) basesystem="Unknown";;
	esac
	shift 2
	elif [ "$1" = "-n" ]
	then
		num=$2
		shift 2
	else
		echo "Program $0 does not recognize option $1"
		exit 1
	fi
done
output=`echo "obase=$ob;ibase=10; $num;" | bc`
echo "$num Decimal number = $output in $basesystem number system(base=$ob)"
