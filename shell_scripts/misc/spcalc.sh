#!/bin/bash
if [ $# -eq 0 ] || [ $# -eq 1 -a "$1" == "-h" ]
then
	echo "Usage: mycalc [OPTION] operand1 operand2 [OPTION] operand1 operand2 ..."
	exit 1;
else
	echo "Welcome to my special calculator"

	while [ ! -z $1 ]
	do
	if [ -z $2 ] || [ -z $3 ]
	then
		echo "invalid number and sequence of inputs"
		exit 1
	else
	
		case $1 in
		'-a') echo "Addition is " `echo "scale=2;$2+$3"|bc`
			;;	
		'-s') echo "Subtraction is " `echo "scale=2;$2-$3"|bc`
			;;
		'-m') echo "Multiplication is " `echo "scale=2;$2*$3"|bc`
			;;
		'-d') echo "Division is " `echo "scale=2;$2/$3"|bc`
			;;	
		esac
		shift 3
	fi
	done
	exit 0
fi
