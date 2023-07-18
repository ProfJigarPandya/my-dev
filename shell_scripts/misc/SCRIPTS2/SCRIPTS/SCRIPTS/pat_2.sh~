# A  

# B  C

# D  E  F  

# G  H  I  J  

# K  L  M  N  O  

# design pattern as above:

#solution is as follows:

Char=101

for ((i=1;i<=5;i++))
{
  for ((j=1;j<=i;j++))
    {
        echo -ne " \\0$Char "
        Char=`echo "ibase=8;obase=8;$Char + 1"|bc`
    }
echo -e  " \n"
}
