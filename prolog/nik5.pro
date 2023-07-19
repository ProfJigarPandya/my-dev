trace

predicates
	count.
	count1(integer).
clauses
	count:-write("input a no: \n")
	,readint(Num),Num<100,count1(Num).
	count1(101).
	count1(Num):-write(Num),nl,NN=Num+1
	,count1(NN).
	
