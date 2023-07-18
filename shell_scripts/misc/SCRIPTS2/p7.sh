# triangle for  "*" 

no=5

for((i=1 ; i<=no ; i++ ))
do
   for((s=no ; s>=i ; s--))

    do
           echo -n " "
    done


  for((j=1; j<=i ; j++))
   do
      echo -n " *"
   done

echo ""
done
