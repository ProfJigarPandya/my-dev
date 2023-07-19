# A  

# B  C

# D  E  F  

# G  H  I  J  

# K  L  M  N  O  

# design pattern as above:

#solution is as follows:

Char=101
#101 is in octal. Equivalent decimal ascii is 65 for A.

for ((i=1;i<=5;i++))
{
  for ((j=1;j<=i;j++))
    {
        echo -ne " \\0$Char " #\0n means ASCII character represented by the octal value n, where n cant exceed 0377 decimal value of 255
        Char=`echo "ibase=8;obase=8;$Char + 1"|bc`
    }
echo -e  " \n"
}

Char=141
#141 is in octal. Equivalent decimal ascii is 97 for a.
for ((i=1;i<=5;i++))
{
  for ((j=1;j<=i;j++))
    {
        echo -ne " \\0$Char " #\0n means ASCII character represented by the octal value n, where n cant exceed 0377 decimal value of 255
        Char=`echo "ibase=8;obase=8;$Char + 1"|bc`
    }
echo -e  " \n"
}

