
# The easiest way to get ggplot2 is to install the whole tidyverse:
install.packages("tidyverse")
install.packages("gplot2")

library(ggplot2)
headers<-c("PartyName","Votes")

#one
my_data_frame<-data.frame(partyNames<-c("Party A", "Party B", "Party C", "NOTA"),partyVotes<-c(20,50,25,5))
names(my_data_frame)<-headers
print(my_data_frame)
ggplot(my_data_frame,aes(x=partyNames,y=partyVotes))+
  geom_bar(stat="identity")+
  labs(title = "Election Result Party wise",
       x = "Party Name",
       y = "Total Votes")
#two
my_data_frame<-data.frame(partyNames<-c("Party A", "Party B", "Party C", "NOTA"),partyVotes<-c(20,50,25,5))
names(my_data_frame)<-headers
print(my_data_frame)
ggplot(my_data_frame,aes(x=partyNames,y=partyVotes))+
  geom_bar(stat="identity")+
  labs(title = "Election Result Party wise",
       x = "Party Name",
       y = "Total Votes")+
  coord_polar("y", start = 0)

#three
my_data_frame<-data.frame(partyNames<-c("Party A", "Party B", "Party C", "NOTA"),partyVotes<-c(20,50,25,5))
names(my_data_frame)<-headers
print(my_data_frame)
ggplot(my_data_frame,aes(x="",y=partyVotes,fill=partyNames))+
  geom_bar(stat="identity")+
  labs(title = "Election Result Party wise",
       x = "Party Name",
       y = "Total Votes")+
  coord_polar("y", start = 0)+
  theme_classic()


