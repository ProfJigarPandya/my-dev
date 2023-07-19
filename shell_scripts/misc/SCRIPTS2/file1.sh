echo "enter a file name :"
read f_name

if [ ! -z "$f_name" ]
then 
	if [ -r "$f_name" -a -w  "$f_name" -a -x "$f_name" ] ; then
        echo " file is having all the permissions "
        else
        echo " read write and execute permission denied "
        fi
else
     echo "file not exist"
fi
