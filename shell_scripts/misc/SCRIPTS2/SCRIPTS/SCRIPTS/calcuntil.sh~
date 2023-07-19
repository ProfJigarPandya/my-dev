ans=y


until [ $ans == "n" ]

do
echo "Enter two values"
read a b 
echo "Enter operator"
read op


case $op in

+) x=`expr $a + $b`
   echo "$x" ;;
-) x=`expr $a - $b`
   echo "$x" ;;
/) x=`expr $a / $b`
   echo "$x" ;;
"*") x=`expr $a \* $b`
   echo "$x" ;;
*)echo "sry" ;;

esac
echo "Enter n to stop "
read ans
done
