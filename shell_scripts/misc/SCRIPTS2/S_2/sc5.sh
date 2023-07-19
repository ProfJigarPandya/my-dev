#
#read from the user
#
echo "program name : $0  "
echo "total no of arguments : $# "
echo "the arguments are : $* "
grep "$2" $1
echo " lines are printed for the searched pattern "
