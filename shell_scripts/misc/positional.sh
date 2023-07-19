#!/bin/bash
# Talking about positional parameters
#	$1, $2, .... positional parameters representing command line arguments
#	$# Total Argument count. This does not count the program name itself.
#	$0 name of the program/command
#	$* Complete set of parameters as one big string
#	"$@" Each quoted string is treated as a sequence argument

clear
if [ $# -eq 0 ];
then
	echo "No arguments provided to the $0 shell script or command."' [ using $0 ]'
	exit 1
else
	echo "Total arguments provided $#"' [ using $# ]'
	echo "Arguments as one big string is $*"' [ using $* ]'	
	echo "Arguments as one big string is $@"' [ using $@ ]'	

	echo "All the arguments from the list as below :"
	echo 'Traversing through $* or $@'
	for arg in $* #for arg in "$@"
	do
		echo $arg
	done

	echo 'Refering $1 till last count of argument'
	for ((i=1; i<=$#; i++))
	do
		echo "At $i is ${!i}"
	done

	echo "Accessing last parameter directly ${!#}"

	echo "Have a nice day!!"
	exit 0
fi
