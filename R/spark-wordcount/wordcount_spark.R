
# R Spark Word Count Example
#%This script demonstrates word count using both SparkR and sparklyr.

# -----------------------------
# SparkR Version
# -----------------------------
# Uncomment the following lines if SparkR is available in your Spark installation
# library(SparkR)
# sparkR.session(master = "spark://localhost:7077", appName = "SparkRWordCount")
# text_file <- read.text("/path/to/input.txt")
# words <- flatMap(text_file, function(line) { strsplit(line, " ")[[1]] })
# word_pairs <- lapply(words, function(word) { list(word, 1) })
# word_counts <- reduceByKey(word_pairs, "_1", function(x, y) { x + y })
# result <- collect(word_counts)
# print(result)
# sparkR.session.stop()

# -----------------------------
# sparklyr Version
# -----------------------------
install.packages("sparklyr")
library(sparklyr)
library(dplyr)

# Connect to Spark
sc <- spark_connect(master = "spark://localhost:7077")

# Read text file
text_tbl <- spark_read_text(sc, name = "text_data", path = "/path/to/input.txt")

# Split lines into words
words_tbl <- text_tbl %>%
	mutate(word = strsplit(value, " ")) %>%
	select(word) %>%
	sdf_explode(word)

# Count words
word_count_tbl <- words_tbl %>%
	group_by(word) %>%
	summarise(count = n()) %>%
	arrange(desc(count))

# Collect and print results
result <- collect(word_count_tbl)
print(result)

# Disconnect from Spark
spark_disconnect(sc)
