echo "enter 3 numbers : "

read a b c

if [ $a -gt $b -a $a -gt $c ] ; then

echo " a is greatest "

elif [ $b -gt $a -a $b -gt $c ] ; then

echo " b is greatest "

elif [ $c -gt $a -a $c -gt $b ] ; then 

echo " c is greatest"

else

echo "all are same"

fi