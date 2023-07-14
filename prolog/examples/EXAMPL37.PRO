              /* Program 37 */
predicates
    inspiral(integer)
goal
    graphics(2,1,0),inspiral(70).
clauses
    inspiral(X):-
        forward(5000),right(X),Y=X+1,inspiral(Y).

