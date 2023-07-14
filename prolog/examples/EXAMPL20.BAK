                /* Program  20  */

domains
    integerlist = integer*
predicates
    writelist(integerlist)
    write5(integerlist,integer)
clauses
    writelist( NL )   :- nl, write5( NL, 0 ), nl.

    write5( TL, 5 )   :-!, nl, write5( TL, 0).
    write5( [H|T], N ) :- write(H," "),N1=N+1,write5(T,N1).
    write5( [], _ ).
