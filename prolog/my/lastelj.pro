domains 
 list = integer*
predicates
 lastele(list,integer)
clauses
 lastele([Last],Last).
 lastele([H|T],Ele):-lastele(T,Ele).
 