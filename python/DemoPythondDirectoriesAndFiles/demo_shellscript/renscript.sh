#Removing all numbers from file names to deceipt secret message from sorted names of directories/files.
for original_name in `ls`
do
	echo $original_name
	new_name=`echo $original_name | sed 's/[0-9]*//g'`
	mv $original_name $new_name
done;
