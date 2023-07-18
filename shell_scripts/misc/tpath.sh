#!/bin/bash
#Program that looks at every component of PATH and checks whether the directory exists and is also accessible.


for var in `echo $PATH | tr ":" "\n"`
do 
	#echo $var
	if [ -d $var ]
	then 	
		if [ -x $var ]
		then
			echo  " $var does exist and is accessible."
		else
			echo  " $var exist but not accessible. "
		fi

	else 
		echo " $var does NOT exist."
	fi
done

