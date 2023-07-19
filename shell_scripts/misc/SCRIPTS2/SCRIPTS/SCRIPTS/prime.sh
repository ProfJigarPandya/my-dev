clear
echo "enter a number"
read num
counter=0
for counter in 2 3 5 7 11 13 17
do

a=`expr $num %  $counter`
echo $a
    if [ $a -eq  0 ]
    then
      echo "not prime"
      exit 0
    fi
done 

echo " prime"

exit 0
