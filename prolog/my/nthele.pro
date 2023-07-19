domains
 l=integer*
predicates
 nthele(l,integer)
clauses
 nthele([H|_],N):-N=1,write("nth ele of list is ",H),nl.
 nthele([H|T],No):-N=No-1,nthele(T,N). 