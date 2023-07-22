hdfs dfs -mkdir -p /user/jigar/my-dev/mapreduce/WordCount/input
hdfs dfs -ls /user/jigar/my-dev/mapreduce/WordCount/input
hdfs dfs -put datafiles/*.txt /user/jigar/my-dev/mapreduce/WordCount/input
hdfs dfs -cat /user/jigar/my-dev/mapreduce/WordCount/input/*.txt
