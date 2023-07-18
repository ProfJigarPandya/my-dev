#!/bin/bash
#Develop shell script which provides a menu for user to execute below mentioned customized features. Provide exist status for 1 to 4 choices as success. And if any other key pressed exit with failure.  Press 1 for displaying every component of $PATH on new line.
#                      Press 2 for finding how many lines of data.txt has matching pattern. Obtain  
#                                  patterns from pattern file patterns.txt, one per line. 
#                     Press 3 for checking whether the input file exist and is having execute permission.
#                     Press 4 for finding whether the input number is odd or even. 

echo 'Press 1 for displaying every component of $PATH on new line.'
echo 'Press 2 for finding how many lines of data.txt has matching pattern. '
echo 'Press 3 for checking whether the input file exist and is having execute permission.'
echo 'Press 4 for finding whether the input number is odd or even. '

read choice
	case $choice in
	1)
		for var in `echo $PATH | tr ":" "\n"`
		do 
			echo $var
		done
		exit 0 # Success
		;;
	2)
		echo 'Enter pattern to be searched from data.txt'
		read pattern
		grep -c $pattern data.txt
		exit 0 # Success
		;;
	3)
		echo 'Enter input file name'
		read filename
		if [ -x $filename ]
		then
			echo  " $filename exists and is executable."
		else
			echo  " $var does not exist or not executable. "
		fi
		exit 0 # Success
		;;
	4)
		#Assumption is that input is a valid number
		echo 'Enter input for checking odd or even'
		read input

		modulo=`expr $input % 2`
		#echo $modulo
		if [ $modulo -eq 1 ]
		then
		        echo "Input number $input is a odd number"
		else
		        echo "Input number $input is an even number"
		fi
		exit 0 # success
		;;	
	*)
		echo 'Option not supported'
		exit 1 # Failure
esac
echo 'Have a nice day!! You will not see this.'
