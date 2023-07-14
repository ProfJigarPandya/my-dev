setwd("DSE")
mat=matrix(data=c(1,2,1,2,4,0,3,6,0),nrow=3,ncol=3,byrow = TRUE)
mat
install.packages("pracma")
library(pracma)
Rank(mat)#Shows number of independent variables based on data column/attributes wise
rank(mat)#case sensitive rank Vs Rank


matt=matrix(data=c(1,3,2,4),nrow=2,ncol=2,byrow=TRUE)
matt

library(pracma)
Rank(matt)


A=matrix(data=c(1,2,3,4),nrow=2,ncol=2,byrow=FALSE)
b=c(7,10)
A
x=solve(A)
?solve
x
library(matlab)
library(pracma)
y=inv(A)
y
xx=solve(A)%*%b
xx
xxx=solve(A,b)
xxx


A=matrix(data=c(1,2,2,4),nrow=2,ncol=2,byrow=FALSE)
b=c(5,10)
A
x=solve(A)
x
xx=solve(A)%*%b
xx
xxx=solve(A,b)
xxx


da=matrix(data=c(0,4,1,4,0,2,0,0,0,3,0,3,0,0,0,0),nrow=4,ncol=4,byrow=FALSE)
da
library(pracma)
r=Rank(da)
r
