#
# 3rd form------ if-then-elif-then-else-fi
#
if [ $# -eq 0 ] ; then 
	echo "Enter string name :"
	read p_name

		if [ -z "$p_name" ] ; then 
 		echo "you have not entered the string" ; exit 1
		fi

	echo "Enter the file name :"
	read f_name

		if [ ! -n "$f_name" ] ; then
		echo "you have not entered the file name" ; exit 2
		fi

        sh sc20.sh "$f_name" "$p_name"
else 
	echo "$#" 	
	#sh sc20.sh "$*"
	sh sc20.sh "$@"
	
fi
