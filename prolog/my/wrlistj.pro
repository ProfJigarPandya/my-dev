domains
 list = symbol*
predicates
 wlist(list)
clauses
 wlist([]).
 wlist([H|T]):-write(H),nl,wlist(T).
 