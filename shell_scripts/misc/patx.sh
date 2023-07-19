#!/bin/bash
echo "Enter n"
read n
x=0
for ((i=1;i<=n;i++))
do
	for((j=1;j<=i;j++))
	do	
		#echo -n $((i*j))" "
		x=`expr $i + $x`
		echo -n "$x "
	done
	echo 
done
