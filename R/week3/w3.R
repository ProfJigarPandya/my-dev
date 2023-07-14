library(dplyr)
dcsv=read.csv(file="seatbelts.csv")
dcsv[1,]
typeof(dcsv[1])
lapply(dcsv[4],'mean')

rt=read.table(file="seatbelts.csv",sep = ",",header = T)
length(rt)
rt['Year']

rt['kms']
lapply(rt['kms'],'max')
library(dplyr)
r8=subset(rt, rt$Year==1984)
r8
s=lapply(r8['front'],'sum')
s

r7=subset(rt, rt$law==1)
tally(r7)

q=lapply(r7['DriversKilled'],'sum')
ress=q/tally(r7)
ress


vf=var(rt$front)
vr=var(rt$rear)
vf
vr

help(var)
