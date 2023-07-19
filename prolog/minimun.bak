domains
	l=integer*
predicates
	min(l,integer)
	mini(l,integer,integer)
clauses
	min([H|T],Min):-mini([H|T],H,Min).
	mini([],Min,Min).
	mini([H|T],Temp,M):- H<Temp,mini(T,H,M).
	mini([H|T],Temp,M):- H>=Temp,mini(T,Temp,M).
