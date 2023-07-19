#
# 3rd form------ if-then-elif-then-else-fi
#
if test $# -eq 2
then 
grep "$2" $1 || echo "Pattern not found"
else
echo "you hav not entered two arguments"
fi
