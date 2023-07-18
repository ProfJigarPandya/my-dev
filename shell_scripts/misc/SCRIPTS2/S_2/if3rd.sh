#
# 3rd form------ if-then-elif-then-else-fi
#
if test $# -eq 0
then 
echo "enter the arguments"
read pname fname
grep "$pname" $fname && echo "pattern found"

elif test $# -eq 2
then
grep "$2" $1 || echo "Pattern not found"

else

echo "you hav not entered two arguments"

fi
