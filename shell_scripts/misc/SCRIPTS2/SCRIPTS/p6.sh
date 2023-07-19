#       1
#      2 2
#     3 3 3
#    4 4 4 4
#   5 5 5 5 5

n=5

for (( i=1;i<=n;i++))
do
  for ((s=$n; s>=i ; s--))
  do
    echo -n " "
  done


 for (( j=1; j<=$i ; j++))
 do
    echo -n " $i"
 done

echo ""

done  
  
