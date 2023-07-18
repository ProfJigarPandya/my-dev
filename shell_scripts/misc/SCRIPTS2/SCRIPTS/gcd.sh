
m=$1 
n=$2

while [ `expr $m % $n ` -ne 0 ]
do

 m=`expr $m % $n`
 temp=$n
 $n=$m
 $m=$temp


done

echo $n






