# R Spark Word Count

This project demonstrates a word count program using R and Apache Spark.

## Prerequisites
- R installed locally
- Spark cluster running (Docker recommended)
- Hadoop 3.4.1 running (Docker)
- SparkR package installed in R

## Setup
1. Start your Hadoop and Spark clusters using Docker.
2. Place your input text file in HDFS or a local path accessible to Spark.
3. Update the path in `wordcount_spark.R` to your input file location.

## Running the Program
1. Open R or RStudio.
2. Set your working directory to this project folder.
3. Run the script:
   ```R
   source("wordcount_spark.R")
   ```

## Notes
- Ensure Spark master URL matches your Docker setup (default: `spark://localhost:7077`).
- You may need to install SparkR: `install.packages("SparkR")` or use the version bundled with Spark.
- For HDFS input, ensure the file path is accessible from the Spark cluster.
