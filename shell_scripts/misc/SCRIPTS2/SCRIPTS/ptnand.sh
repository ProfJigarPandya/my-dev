#
#read from the user
#
echo " enter file name : "
read fname
echo " enter pattern name : "
read pname
grep "$pname" $fname && echo "pattern found in file"
echo $?


