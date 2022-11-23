ip=192.168.96.102
username=jigar
sshport=1985
if [ $# -eq 0 ]
then
        ssh $username@$ip -p $ssport
else
        sshpass -p $1 ssh $username@$ip -p $sshport
fi

