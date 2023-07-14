
             /* Program 25 */
domains
    list = integer*
predicates
    member(integer,list)
    intersect(list,list,list)
clauses
    member(X,[X|_]).
    member(X,[_|Y]):- member(X,Y).

    intersect([],_,[]).
    intersect([H|T],Y,[H|T2]):-
        member(H,Y),!,intersect(T,Y,T2).
    intersect([_|T],Y,Z):- intersect(T,Y,Z). 
    