              /* Program 47 */
domains
    namelist = name*
    name  = symbol
predicates
    string_namelist(string,namelist)
clauses
    string_namelist(S,[H|T]):-
        fronttoken(S,H,S1),!,string_namelist(S1,T).
    string_namelist(_,[]).
