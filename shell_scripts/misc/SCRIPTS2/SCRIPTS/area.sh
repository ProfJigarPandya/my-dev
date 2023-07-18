echo "Enter T or C "
read ch

if test "$ch" = "[tT]"
then

echo "Enter the value of hight and base:"

read h b

a=`echo " scale=5 ; ( $h * $b ) / 2 "| bc `
echo "area of triangle is : $a "

elif test "$ch" = "[cC]"
then
echo " Enter the radius :"
read r

ac=`echo "scale=2 ; 3.14 * ( $r^2 ) " | bc`
echo "area of circle is : $ac"

else

echo "enter proper choice"

fi

