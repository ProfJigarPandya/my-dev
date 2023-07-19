#
# 2nd form------ if-then-else-fi
#
echo -e "Enter the file name and pattern name : \n"
read fname pname
if grep "$pname" $fname
then 
echo "Pattern found"
else
echo "Pattern not found"
fi
