                /* Program 19 */
domains
       integerlist = integer*
       namelist    = symbol*
predicates
       writelist(integerlist)
       writelist(namelist).
clauses
       writelist([]).
       writelist([H|T]) :- write(H," "), writelist(T).
