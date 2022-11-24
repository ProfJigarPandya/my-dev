flag=0;
for dip in `cat ip.lst`
do
        ssh jigar@$dip exit
        status=`echo $?`
        if test $status -ne 0
        then
                echo "Status: SSH is not successful to $dip"
                flag=1
        fi
done;
if test $flag -eq 0
then
        echo "Status: All SSH is successful."
fi;

