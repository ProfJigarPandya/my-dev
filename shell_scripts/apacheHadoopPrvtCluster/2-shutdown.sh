labsubnet=192.168.32
passw=test
for i in {33..51};
do
	sshpass -p $passw ssh -o StrictHostKeyChecking=no root@$labsubnet.$i "/sbin/shutdown -h now"
done;

