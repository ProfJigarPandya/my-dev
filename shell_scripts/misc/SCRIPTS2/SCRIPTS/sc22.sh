echo "enter marks of 5 subjects :"
read m1 m2 m3 m4 m5

per=`expr \( $m1 + $m2 + $m3 + $m4 + $m5 \) \* 100  / 500`
echo $per

if [ $per -ge 60 ]
then 
echo "First class"
fi

if [ $per -ge 50 -a $per -lt 60 ]
then 
echo "second class"
fi

if [ $per -ge 40 -a $per -lt 50 ]
then
echo "third class"
fi

if [ $per -lt 40 ]
then
echo "fail"
fi
