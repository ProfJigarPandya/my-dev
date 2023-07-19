code = 1000 trail = 1000
domains
	term = reference var(vid); symb(symbol) ; 
	       cmp(fid, terml)
	terml = reference term*
	atom = atom(aid, terml)
	atoml = atom*
	e = e(vid, term)
	env = reference e*
	fid, aid, vid = symbol
	
database
	clause(atom, atoml)
	
predicates
	call(atom)
	unify_term(term, term, env)
	unify_terml(terml, terml, env)
	unify_littl(atoml, env)
	member(e, env)

/*goal call(atom(likes,[Name,Activity])),
        write(Name,Activity).*/

clauses
        call(atom(Id, Terml)) :-
 		clause(atom(Id,Terml1), Body),
		free(E), 
		unify_terml(Terml, Terml1, E), 
		unify_littl(Body, E).
	unify_terml([], [], _).
	unify_terml([Trm1|Tl1],[Trm2|Tl2],E) :-
		unify_term(Trm1, Trm2, E),
		unify_terml(Tl1, Tl2, E).
		
	unify_term(Term, var(X), Env) :- 
		member(e(X,Term),Env), !.
	unify_term(symb(X), symb(X), _).
	unify_term(cmp(Id, L1), cmp(Id,L2),E) :-
		unify_terml(L1, L2, E).
		
	unify_littl([],_).
	unify_littl([atom(Id,Terml)|Atoml],Env) :-
		unify_terml(Call,Terml,Env),call(atom(Id,Call)),
		unify_littl(Atoml,Env).
		
	member(X,[X|_]).
	member(X,[_|L]) :-
		member(X,L).

/* *********************************************************** */
/* 	DATABASE FACTS ASSERTED  *                             */  
/* *********************************************************** */
         clause(atom(likes,[symb(tom),symb(baseball)]), []).        
         clause(atom(likes,[symb(windy),symb(tennis)]), []).
 	 clause(atom(likes,[symb(john),symb(football)]), []).
 	 clause(atom(likes,[symb(eric),symb(swimming)]), []).
         clause(atom(likes,[symb(bill),var(x)]),	
        	   [atom(likes,[symb(tom), var(x)])]).
