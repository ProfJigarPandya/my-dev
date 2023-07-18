str1="hello"
str2="good"
str3=""
str4="hello"
echo "there are four strings : str1: $str1, str2: $str2 , str3: $str3, str4: $str4 "
echo " check  str1 = str2:"
[ "$str1" = "$str2" ]
echo $?
echo "check str != str2:"
[ "$str1" != "$str2" ] 
echo $?
echo "check -n str1:"
[ -n "$str1" ]
echo $?
echo "check ! -n  str1:"
[ ! -n "$str1" ]
echo $?
echo "check str3 has assigned some value:"
[ "$str3" ]
echo $?
echo "check -z str3:"
[ -z "$str3" ]
echo $?
echo "check ! -z  str3"
[ ! -z "$str3" ]
echo $?
echo "check str1==str4"
[ "$str1" == "$str4" ]
echo $?
