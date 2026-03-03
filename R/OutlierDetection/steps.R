cars
head(cars)
tail(cars)

summary(cars)
fivenum(x=cars$speed)
fivenum(x=cars$dist)
IQR(x=cars$speed)
IQR(x=cars$dist)
mean(x=cars$speed)
mean(x=cars$dist)

class(cars)
mode(x=cars$speed)#Not mode meaning which has occurred maximum time. Its the attribute type/storage mode here.
mode(x=cars$dist)#output: numeric
boxplot(x=cars$speed,horizontal = TRUE)
boxplot(x=cars$dist,horizontal=TRUE)


lm(dist~speed,data=cars)#Fitting linear models

lm(speed~dist,data=cars)#Fitting linear models

