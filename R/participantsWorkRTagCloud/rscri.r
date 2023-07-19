library("tm")
library("corpus")
library("SnowballC")
cname <- file.path("C:\\my-dev\\R\\participantsWorkRTagCloud", "data")
dir(cname)
text_corpus <- Corpus(DirSource(cname))
text_corpus <- tm_map(text_corpus, stripWhitespace)
text_corpus <- tm_map(text_corpus, content_transformer(tolower))
text_corpus <- tm_map(text_corpus, removeWords, stopwords("english"))
text_corpus <- tm_map(text_corpus, stemDocument)
text_corpus <- tm_map(text_corpus, removeNumbers)
text_corpus <- tm_map(text_corpus, removePunctuation)
dtm <- DocumentTermMatrix(text_corpus)
freq <- sort(colSums(as.matrix(dtm)), decreasing=TRUE)
head(freq)
library(wordcloud)
wordcloud(names(freq), freq, min.freq=100)
