cl="gnome-terminal"
username=jigar
for ip in `cat ip.lst`
do
        cl="$cl --tab -e \"ssh $username@$ip\""
done
eval "$cl"
exit
