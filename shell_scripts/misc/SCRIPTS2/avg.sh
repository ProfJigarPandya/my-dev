read n
s=0
for ((i=1;i<=n;i++))
do 
read a
s=`expr $s + $a`
done

avg=` echo " scale=3; $s / $n " | bc`

echo "avg of $n no is : $avg "

