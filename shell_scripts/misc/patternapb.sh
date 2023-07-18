#!/bin/bash
echo "Enter n"
read n
for ((i=1;i<=n;i++))
do
	x=0
	for((j=1;j<=i;j++))
	do	
		#echo -n $((i*j))" "
		#echo -n `expr $i \* $j`" "
		x=`expr $x + $i`
		echo -n "$x "
	done
	echo 
done
