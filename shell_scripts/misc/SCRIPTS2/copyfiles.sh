#
# 1st form------ if-then-fi statement
#example of copying two files
#
echo -e "Enter the source file and target file  name : \n"
read source target
if cp $source $target
then 
echo "file copied succesfully"
fi
