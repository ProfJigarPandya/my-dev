function fact
{

   if [ $1 -eq 1 ]
    then  
     echo "1"
    else
      
     fact `expr $1 - 1 `

     fi
}

fact 5


