echo "Welcome, this program shows 2 power n series"
echo "Enter n "
read n
clear
echo "Byte Power series 2, "$n
x=1
echo $x
#for ((  i = 1 ;  i <= $n;  i++  ))
for i in ` seq 1 $n`
do
  #echo "Welcome $i times"
  y=`expr $x + $x`
  echo $y 
  x=$y
done

