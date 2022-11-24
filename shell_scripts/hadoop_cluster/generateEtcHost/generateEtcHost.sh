echo -n '' > hadoopEtcHosts

for ip in `cat ip.lst`
do
        number=`echo $ip | cut -d . -f 4`
        echo "$ip hadoop-$number" >> hadoopEtcHosts
done
