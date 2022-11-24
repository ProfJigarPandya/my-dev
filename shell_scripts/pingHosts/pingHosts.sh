subnet=192.168.96
for ip in $(seq 1 254)
do 
	echo "Pinging $subnet.$ip..."
        ping -c 1 -W 3 $subnet.$ip>/dev/null; 
        [ $? -eq 0 ] && echo "$subnet.$ip is UP" || : ;
done
