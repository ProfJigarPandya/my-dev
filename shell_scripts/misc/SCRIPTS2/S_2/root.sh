function abs()
{
    if [ `echo " scale=10; $1 >= $2"|bc` -eq 1 ]

   then 

       echo "`echo "scale=10; $1 - $2 " |bc` "

   else

      echo "`echo "scale=10; $2 - $1 " |bc ` "

   fi


}






echo "enter a number"

read Num

Root2=1;
Root1=$Num;
diff=$Num;
while [ `echo " scale=10; $diff >= 0.00000001 " | bc` -eq 1 ]
do 


Root1=`echo "scale=20;($Root1 + $Root2) / 2;"|bc`

Root2=`echo "scale=20; $Num / $Root1;"|bc`

echo "Root1:$Root1"
echo "Root2:$Root2"

diff=`abs $Root1 $Root2`


done


echo " Root is: $Root1"
