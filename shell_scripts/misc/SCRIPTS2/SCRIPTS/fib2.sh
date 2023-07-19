
Counter=1
prev=1
cur=1

echo $prev $cur


while [ $Counter -le 10 ]

 do 

 next=`expr $prev + $cur`
 
 echo "$next"
 
 prev=$cur
 cur=$next
 Counter=`expr $Counter + 1`




done


