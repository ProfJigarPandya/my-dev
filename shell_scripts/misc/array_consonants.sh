#!bin/bash
echo -n "Enter:"
read a
alpha=(a b c d e f g h i j k l m n o p q r s t u v w x y z)
for ((i=0;i<a;i++))
do
if [ ${alpha[$i]} = a ] || [ ${alpha[$i]} = e ] || [ ${alpha[$i]} = i ] || [ ${alpha[$i]} = o ] || [ ${alpha[$i]} = u ]
then
let a=a+1
else
echo -n "${alpha[$i]}"
fi
done
echo ""
