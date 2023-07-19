domains
	integer=symbol
predicates
	count(integer)
clauses
	count(11).
	count(N):-write(N),nl,
		count(N+1).        
