	<property>
                <name></name>
                <value></value>
        </property>



#root
groupadd hadoop
adduser -g hadoop hduser
passwd hduser

#As hduser - self equivalence
ssh-keygen -t rsa -P '' -f ~/.ssh/id_rsa
ssh-keygen -t dsa -P '' -f ~/.ssh/id_dsa
cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys
chmod 600 .ssh/authorized_keys


#For all participating nodes, achieve user equivalence


for sip in `cat ip.lst`
do
	echo hduser@$sip:/home/hduser/.ssh/id_rsa.pub
	lf=`echo "$sip.pub"`
	echo $lf
	scp hduser@$sip:/home/hduser/.ssh/id_rsa.pub $lf
done


for sip in `cat ip.lst`
do
        echo hduser@$sip:/home/hduser/.ssh/id_dsa.pub
        lf=`echo "$sip.bup"`
        echo $lf
        scp hduser@$sip:/home/hduser/.ssh/id_dsa.pub $lf
done



for filename in `ls *.pub`
do
cat $filename >> allpub.keys
done


for filename in `ls *.bup`
do
cat $filename >> allpub.keys
done



for ip in `cat ip.lst`; do scp allpub.keys hduser@$ip:/home/hduser/.ssh/authorized_keys; done;


flag=0;
for dip in `cat ip.lst` 
do
	ssh hduser@$dip exit
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




cl="gnome-terminal"
for ip in `cat ip.lst`
do
	cl="$cl --tab -e \"ssh hduser@$ip\""
done
eval "$cl"


for ip in `cat ip.lst`; do scp $1 hduser@$ip:/home/hduser/; done;


echo "for ip in `cat ip.lst`; do scp $1 hduser@$ip:/home/hduser/; done;" > myscp.sh

chmod +x myscp.sh

./myscp.sh jdk-8u121-linux-x64.tar.gz

tar xvzf jdk-8u121-linux-x64.tar.gz

cp -R /home/hduser/jdk1.8.0_121 /opt/
chown -R hduser:hadoop /opt/jdk1.8.0_121/




vi /etc/sysconfig/network
HOSTNAME=hadoop-master



tar xvzf hadoop-2.8.0.tar.gz --Directory

ln -s hadoop-2.8.0 hadoop

chown hduser:hadoop /opt/hadoop /opt/hadoop-2.8.0

HADOOP_PREFIX=/opt/hadoop
export HADOOP_PREFIX



mkdir /usr/hadoop_storage

mkdir /usr/hadoop_storage/namedir 
mkdir /usr/hadoop_storage/datadir
chown -R hduser:hadoop /usr/hadoop_storage/


vi /etc/hosts
192.168.26.15 hadoop-master
192.168.26.16 hadoop-slave16
192.168.26.17 hadoop-slave17
192.168.26.18 hadoop-slave18


./hduserscp.sh allnode/core-site.xml /opt/hadoop/etc/hadoop/ ip.lst

./hduserscp.sh allnode/datanodes.lst /opt/hadoop/etc/hadoop/

./hduserscp.sh namenode/hdfs-site.xml /opt/hadoop/etc/hadoop namenodeip.lst


./hduserscp.sh datanode/hdfs-site.xml /opt/hadoop/etc/hadoop/ datanodeip.lst


./hduserscp.sh slaves/slaves /opt/hadoop/etc/hadoop/ namenodeip.lst
./hduserscp.sh slaves/slaves /opt/hadoop/etc/hadoop/ datanodeip.lst


./hduserscp.sh ResourceManager/yarn-site.xml /opt/hadoop/etc/hadoop/ ResourceManager/resourcemanagerip.lst


./hduserscp.sh allnode/mapred-site.xml /opt/hadoop/etc/hadoop ip.lst



$HADOOP_PREFIX/bin/hdfs namenode -format FirstFourCELab2


$HADOOP_PREFIX/sbin/hadoop-daemon.sh --config $HADOOP_CONF_DIR --script hdfs start namenode

$HADOOP_PREFIX/sbin/hadoop-daemons.sh --config $HADOOP_CONF_DIR --script hdfs start datanode

hduserscp.sh allnode/hadoop-env.sh /opt/hadoop/etc/hadoop ip.lst

hduserscp.sh allnode/mapred-env.sh /opt/hadoop/etc/hadoop ip.lst

hduserscp.sh allnode/yarn-env.sh /opt/hadoop/etc/hadoop ip.lst


bin/hadoop fs -mkdir -p  /user/hduser

netstat -nptl | grep `jps | grep NameNode | cut -d ' ' -f 1`
netstat -nptl | grep `jps | grep DataNode | cut -d ' ' -f 1`
netstat -nptl | grep `jps | grep ResourceManager | cut -d ' ' -f 1`
netstat -nptl | grep `jps | grep NodeManager | cut -d ' ' -f 1`
netstat -nptl | grep `jps | grep JobHistoryServer | cut -d ' ' -f 1`


for ip in `cat ip.lst`; 
do
       scp hbase-1.2.5-bin.tar.gz hduser@$ip:/home/hduser/hbase-1.2.5-bin.tar.gz;        
done;

bin/hadoop fs -put file:///home/hduser/hbase-analytics.tsv hdfs://hadoop-master:9000/tmp
