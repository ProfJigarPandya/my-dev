ans=yes
while [ $ans == "yes" ]
do
	echo "Enter two values"
	read a b 
	echo "Enter operator"
	read op
	case $op in
	 plus|+|pl) 	
			x=`expr $a + $b`
			echo "$x" ;;
	 sub|-|su) 	
			x=`expr $a - $b`
		   	echo "$x" ;;
	 div|/) 
			x=`expr $a / $b`
			echo "$x" ;;
	 mul|"*") 
			x=`expr $a \* $b`
			echo "$x" ;;
	  *)
			echo "sry" ;;
	esac

	echo "Enter yes to continue "
	read ans
done
