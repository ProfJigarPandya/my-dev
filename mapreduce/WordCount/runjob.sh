hdfs dfs -rm -r /user/jigar/my-dev/mapreduce/WordCount/output
hadoop jar wc.jar WordCount /user/jigar/my-dev/mapreduce/WordCount/input /user/jigar/my-dev/mapreduce/WordCount/hadoop_output 2>wc.log
