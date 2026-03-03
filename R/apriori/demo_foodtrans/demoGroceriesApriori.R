#https://www.kaggle.com/datasets/heeraldedhia/groceries-dataset
#https://github.com/stedy/Machine-Learning-with-R-datasets/blob/master/groceries.csv
#https://rpubs.com/Alekssandra/998933

install.packages("Matrix")
install.packages("arules")
install.packages("arulesViz")
library(arulesViz)
library(arules)
data("Groceries")#load
summary(Groceries)
inspect(head(Groceries, 5))

class(Groceries)
head(Groceries)


rules <- apriori(Groceries, parameter = list(supp=0.01, conf=0.2,minlen=2))
class(rules)
inspect(rules)

rules.by.conf<-sort(rules, by="confidence", decreasing=TRUE)
inspect(head(rules.by.conf))

#The count measure indicates the number of transactions in which both events occurred together
ctab<-crossTable(Groceries, measure="count", sort=TRUE) 
head(round(cctab,2))

#The support measure shows how frequently an item appeard in total number of transactions
stab<-crossTable(Groceries, measure="support", sort=TRUE) 
head(round(stab,2))

#The lift measure illustrates how often two given products are bought together than separately
ltab<-crossTable(Groceries, measure="lift", sort=TRUE) 
head(ltab)
#

rules.by.lift<-sort(rules, by="lift", decreasing=TRUE) 
inspect(head(rules.by.lift))


rules.by.count<- sort(rules, by="count", decreasing=TRUE)
inspect(head(rules.by.count))

#Error in as(data, "transactions") : 
#no method or default for coercing “rules” to “transactions”
# 
#

rules_butter <-
  apriori(
    data = rules,
    parameter = list(supp = 0.001, conf = 0.15),
    appearance = list(default = "lhs", rhs = "butter"),
    control = list(verbose = F)
  )
rules_cbeer_dt <- inspect(rules_butter[1:5], linebreak = FALSE)


inspect(freq.items[1:5])