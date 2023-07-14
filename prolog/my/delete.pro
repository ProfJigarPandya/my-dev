/* delete a givin no from a list */

domains
	l=integer*
predicates
	d(l,integer,l)
clauses
	d([],_,[]).
	d([H|T],H,T2):-d(T,H,T2).
	d([H|T],X,[H|T1]):-d(T,X,T1),H<>X.
