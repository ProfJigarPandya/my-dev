              /* Program 36 */
predicates
    polyspiral(integer)
goal
    graphics(2,1,0),polyspiral(500).
clauses
    polyspiral(X):-
        
        
        rward(X),right(62),Y=X+100,polyspiral(Y).
