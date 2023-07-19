#
#read from the user
#
echo " enter file name : "
read fname
echo " enter pattern name : "
read pname
grep "$pname" $fname || echo "pattern not found in file"
#grep "$pname" $fname || exit 1
#echo "pattern found in file"
echo $?


