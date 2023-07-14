trace
domains
	list=integer*
predicates
	append(list,list,list)
clauses
	append([ ],L,L).
        append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
        