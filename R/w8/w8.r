strain=read.csv(file="serviceTrainData.csv",header = TRUE,sep=",")
strain


stest=read.csv(file="serviceTestData.csv",header = TRUE,sep=",")
stest


str(strain)
str(stest)

install.packages("questionr",dependencies = TRUE)
install.packages("ROCRv",dependencies = TRUE)
install.packages("mvtnorm",dependencies = TRUE)
install.packages("nloptr",dependencies = TRUE)
install.packages("curl",dependencies = TRUE)
install.packages("plotmo",dependencies = TRUE)
install.packages("lme4",dependencies = TRUE)
install.packages("prodlim",dependencies = TRUE)
install.packages("httr",dependencies = TRUE)
install.packages("prodlim",dependencies = TRUE)
install.packages("ipred",dependencies = TRUE)
install.packages("recipes",dependencies = TRUE)
install.packages("caret",dependencies = TRUE)
install.packages("class",dependencies = TRUE)

library(caret)
library(class)

predictedKnn=knn(train=strain[,-6],test=stest[,-6], cl=strain$Service,k=3)
summary(predictedKnn)




sntrain=read.csv(file="social_network_train.csv",header = TRUE,sep=",")
sntrain
str(sntrain)
sntest=read.csv(file="social_network_test.csv",header = TRUE,sep=",")
sntest
str(sntest)

predictedSNKnn=knn(train=sntrain[,-3],test=sntest[,-3], cl=sntrain$Purchased,k=3)
summary(predictedSNKnn)
view(predictedSNKnn)
predictedSNKnn
library(caret)
conf_matrix=confusionMatrix(data=predictedSNKnn,sntest$Purchased)

conf_matrix=table(predictedSNKnn,sntest$Purchased)
conf_matrix
