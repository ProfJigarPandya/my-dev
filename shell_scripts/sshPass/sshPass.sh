if [ $# -eq 0 ]
then
        ssh jigar@192.168.96.102
else
        sshpass -p $1 ssh jigar@192.168.96.102
fi

