#1

#2


#3
A=matrix(data=c(1,2,8,2,9,4,5,6,8,7,3,0,5,6,6,5,5,1,10,5,6,1,0,12,1),nrow=5,ncol=5,byrow=FALSE)
A
DA=lapply(list(A),det)
DA
DA2=det(A)
DA2
library(pracma)
Rank(A)
A
res=A%*%matrix(data=c(0,0,3,-1,-1),nrow=5,ncol=1,byrow=F)
res
ma=matrix(1:9,3,3)
ma
dma=lapply(list(ma),det)
dma

mam=matrix(data=c(1,0,0,0,2,0,0,0,3),nrow=3,ncol=3,byrow=FALSE)
mam


#example optimization m>n

#A=matrix(data=c(1,2,3,0,0,1),nrow=3,ncol=2,byrow = F)
A=matrix(data=c(1,2,3,0,0,1),nrow=3,ncol=2,byrow = F)
A
AT=t(A)
AT
ATA=(AT%*%A)
ATA
install.packages("matlab")
library(matlab)
library(pracma)
ATAI=inv(ATA)
ATAI
#b=matrix(data=c(1,-0.5,5),nrow=3)
b=matrix(data=c(1,2,5),nrow=3)
b
det(ATA)

x=ATAI%*%AT%*%b
x


#Eigen
me=matrix(data=c(1,0,0,0,2,0,0,0,3),nrow=3,ncol=3,byrow=F)
me
mei=eigen(me)
mei


#7
#7.1
V1 = matrix(data=c(1,8,4),nrow=3,ncol=1,byrow=T)
V1T=t(V1)
V2 = matrix(data=c(6,7,-8),nrow=3,ncol=1,byrow=T)
R=V1T%*%V2
R #30 #Not Orthogonal


#7.2
V1 = matrix(data=c(1,4,-2),nrow=3,ncol=1,byrow=T)
V1T=t(V1)
V2 = matrix(data=c(12,-2,2),nrow=3,ncol=1,byrow=T)
R=V1T%*%V2
R #0 Orthogonal

#7.3
V1 = matrix(data=c(6,4,-2),nrow=3,ncol=1,byrow=T)
V1T=t(V1)
V2 = matrix(data=c(1,4,-1),nrow=3,ncol=1,byrow=T)
R=V1T%*%V2
R #24 Not Orthogonal

#7.4
V1 = matrix(data=c(-2,6,1),nrow=3,ncol=1,byrow=T)
V1T=t(V1)
V2 = matrix(data=c(4,1,2),nrow=3,ncol=1,byrow=T)
R=V1T%*%V2
R #0 Orthogonal
