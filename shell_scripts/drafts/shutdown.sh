labsubnet=192.168.26
user=root
passw=
for i in {11..59};
do
	sshpass -p $passw ssh -o StrictHostKeyChecking=no $user@$labsubnet.$i "/sbin/shutdown -h now"
done;

