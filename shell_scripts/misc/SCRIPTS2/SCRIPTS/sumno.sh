echo "Enter any no : "
read n
sum=0
l=0

while [ $n -gt 0 ]

do


l=`expr $n % 10`
sum=`expr $sum + $l`
n=`expr $n / 10`
done
echo "reverse is : $sum "


