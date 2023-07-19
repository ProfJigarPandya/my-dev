n=100
sum=0
for(i in seq(1,n,3)){
  sum=sum+i
  print(c(i,sum))
  if(sum>15)
    break
}
i

??right_join


n=5
sum=0
#i
#     1  2  3   4   5    6     7    8    9 10 11
#i+2
#     3  4  5   6   7    8     9    10   11 
#sum  
#   0 3 
#        7
#           12
#               18
#                   25
#                       33
#                             42
#                                   52
#                                         63   

sum=0
for(i in 1:11){
  sum=sum+(i+2)
  print(c(i,month.abb[i+1],sum))
}



#q6
students_scores=read.table("~/DSE/w1q1b6Table1.csv",header=TRUE,sep=",")
students_scores
install.packages("reshape2")
library("reshape2")
melt(students_scores,id.vars="Name",measure.vars=c("Mathematics","English","Science"),variable.name="Variable",value.name="Value")
melt(students_scores,id.vars="Name",measure.vars=c("Mathematics","English","Science"))

  ??melt

help(melt,package="reshape2")


#b7
rank = c(1,2,3)
competitor = c("Usain","Tyson","Yohan")
mark = c(9.58, 9.69, 9.65)
athletics=data.frame(rank,competitor,mark)
athletics
athletics=rbind(athletics,data.frame(rank="4",competitor="Asafa",mark=9.72))
athletics

#b8
athletics=cbind(athletics,nationality=c("JAM","USA","JAM","JAM"))
athletics=cbind(athletics,data.frame(nationality=c("JAM","USA","JAM","JAM")))
athletics

#b9
help(subset)
subset(athletics,athletics$mark<9.69)

#b10



func_multi_o1= function(a,b,c)
{
  result=(a*b)*0.5+(a*c)**0.5 
  #(4*5)*0.5+(4*6)**0.5
  #10+sqrt(24) > 9.37
  return(result)
}
func_multi_o1(4,5,6)#14.89898

func_multi_o2= function(a,b,c)
{
  result=(a*b)**0.5+(a*c)**0.5 
        #(4*5)**0.5+(4*6)**0.5
        #sqrt(20)+sqrt(24)
        #
  return(result)
}
func_multi_o2(4,5,6)#9.371115


func_multi_o3= function(a,b,c)
{
  result=(a*b)**0.5+(a*c)**0.5 
  return(result)
}
func_multi_o3(4,5)
#9.37
