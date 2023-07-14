trace
domains
	list = integer*
predicates
        max(list,integer,integer)
clauses
	max([ ],X,X).
	max([H|T],Temp,Max):-H>Temp,max(T,H,Max).
	max([H|T],Temp,Max):-H<Temp,max(T,Temp,Max).