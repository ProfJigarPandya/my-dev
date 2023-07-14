#Quiz week 0 DSE

vec1 = c(1,2,3)

vec2 = c("Apple","Orange","Guava")

vec3 = c(180,100,50)

vec1

vec2

vec3

fruits = data.frame(vec1,vec2,vec3)

fruits

#1
fruits[2:3,3]

#2
fruits=rbind(fruits,data.frame(vec1=4,vec2="Grapes",vec3="120"))

fruits

#3
fruits=cbind(fruits,vec4=c(10,20,30,40))
fruits=fruits[,-4]
fruits=cbind(fruits,data.frame(vec4=c(10,20,30,40)))

fruits

#6
vec1=c(6,7,8)

vec1

vec2=c("Football","Basketball","Volleyball")

vec2

vec3=c("300","400","600")

mylist=list(vec1,vec2,vec3)
mylist


mylist[[2]][2]="Carrom"

mylist
