echo "Enter any no : "
read n
rev=0
l=0

while [ $n -gt 0 ]

do


l=`expr $n % 10`
rev=`expr $rev \* 10 + $l`
n=`expr $n / 10`
done
echo "reverse is : $rev"


