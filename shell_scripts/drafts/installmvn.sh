labsubnet=192.168.26
user=root
passw=
for i in {11..58};
do
	sshpass -p $passw ssh -o StrictHostKeyChecking=no $user@$labsubnet.$i "apt-get -y install maven"
done;

