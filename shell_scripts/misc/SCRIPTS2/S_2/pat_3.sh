# A  

# A  B  

# A  B  C  

# A  B  C  D  

# A  B  C  D  E  

# design pattern as above:

#solution is as follows:

for ((i=1;i<=5;i++))
{
          Char=101
  for ((j=1;j<=i;j++))
    {

        echo -ne " \\0$Char "
        Char=`echo "ibase=8;obase=8;$Char + 1"|bc`

    }
echo -e  " \n"

}

