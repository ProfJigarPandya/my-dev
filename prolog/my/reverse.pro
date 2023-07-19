
domains
 l = integer*
predicates
 rr(l,l,l)
 
 clauses

 
 rr([],L,L).
 rr([H|L1],L2,L3) :- rr(L1,[H|L2],L3).
 