domains
	l=integer*
predicates
	d(l,integer,integer)
	dd(l,integer,integer,integer,integer)
clauses
	d(L1,O,E):-dd(L1,0,O,0,E).
	dd([],To,To,Te,Te).
	dd([H|T],To,O,Te,E):-H mod 2=0,P=Te+H,dd(T,To,O,P,E).
	dd([H|T],To,O,Te,E):-H mod 2<>0,P=To+H,dd(T,P,O,Te,E).
