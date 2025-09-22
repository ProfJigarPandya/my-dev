install.packages("gplots")
library("gplots")

# use list as input
x <-list('Mathematics'=c('Machine Learning'),'Computer Science Technology'=c('Machine Learning'),'Business Domain Expertise'=c())

# create Venn diagram with three sets
venn(x,showSetLogicLabel = false)


#y <-list('Mathematics'=c(),'Computer Science Technology'=c(),'Biology'=c())

# create Venn diagram with three sets
#venn(y)
