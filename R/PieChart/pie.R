
# The easiest way to get ggplot2 is to install the whole tidyverse:
install.packages("tidyverse")
install.packages("gplot2")

library(ggplot2)
headers<-c("PartyName","Votes")
partyNames<-c("Party A", "Party B", "Party C", "NOTA")
partyVotes<-c(20,50,25,5)
my_data_frame<-data.frame(PartyNames=partyNames,PartyVotes=partyVotes)
print(my_data_frame)
ggplot(my_data_frame) +
  geom_bar(x=partyNames)



