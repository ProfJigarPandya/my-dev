Counter=1
Char=101





while [ $Counter -le  26 ]
do

   
 echo -e \\0$Char
 Char=`echo "ibase=8;obase=8;$Char + 1"|bc`

 Counter=`expr $Counter + 1`

done

