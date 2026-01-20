#age_range<-c("1-5","6-15","16-20","21-50","51-80","81-110")
age_range<-c(1,6,16,21,51,81,110)
frequency_age_range<-c(200,450,300,1500,700,44)

histogram1 <- list(breaks=age_range,counts=frequency_age_range,density=frequency_age_range/diff(age_range)/sum(frequency_age_range),xname="Age Range")
class(histogram1) <- "histogram"


plot(histogram1,main="Title",xlab="Age Range", ylab="Frequency",col="blue",border="black")

