echo "enter marks of 5 subjects :"
read m1 m2 m3 m4 m5

per=`expr \( $m1 + $m2 + $m3 + $m4 + $m5 \) \* 100  / 500`
echo $per

if [ $per -ge 60 ]
then 
echo "First class"

elif [ $per -ge 50 -a $per -lt 60 ]
then 
echo "second class"

elif [ $per -ge 40 -a $per -lt 50 ]
then
echo "third class"

else
echo "fail"
fi
