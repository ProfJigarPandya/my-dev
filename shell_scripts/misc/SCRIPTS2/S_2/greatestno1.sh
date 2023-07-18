echo "Enter 3 values:"
read a b c

if [ $a -gt $2 -a $a -gt $c ]
then 
     echo " a : $a is greatest"

elif [ $b -gt $c ]
then 
    echo " b : $b is greatest "
else 
    echo " c : $c is greatest "
fi
