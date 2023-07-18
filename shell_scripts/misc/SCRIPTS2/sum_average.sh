#sum and average of n numbers and sqare root of sum
echo "enter n"
read n
sum=0

for((j=0;j<$n;j++))
do
echo "enter $j th value"
read a
sum=`expr $sum + $a`
done
echo "sum is $sum"
avg=$(echo "scale=2;$sum/$n"|bc -l)
echo "Average is $avg"
echo "sqrt is "
echo "scale=2;sqrt($sum)"|bc -l
