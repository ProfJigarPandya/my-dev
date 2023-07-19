df=read.table(file="Auto.csv",sep = ",", header = TRUE)
df
help(read.table)
is.na(df)
which(is.na(df))

??setOption
unique (unlist (lapply (df, function (x) which (is.na (x)))))

cor(df$mpg,df$acceleration,method = c("spearman"))
#"pearson", "kendall", "spearman"
cor

linearMod <- lm(dist ~ speed, data=cars)  # build linear regression model on full data
print(linearMod)

lr_model=lm(mpg~.,data=df)
summary(lr_model)


nyc=read.csv("nyc.csv")
nyc
summary(nyc)
plot(nyc,main="Pairwise scator plot")
lm(Price~Food+Decor+Service+East,data=nyc)

nyc_mod_2=lm(Price~Food+Decor+East,data=nyc)
summary(nyc_mod_2)

nyc_mod_3=lm(Price~Service+Decor+East,data=nyc)
summary(nyc_mod_3)


??confusionMatrix
