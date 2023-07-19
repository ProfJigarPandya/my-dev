               /* Program 24 */
domains
    list = integer*
predicates
    readlist(list)
goal
    write("Write a list of integers"),readlist(L),
    write("\nThe Turbo Prolog list is ",L).
clauses
    readlist([H|T]) :- readint(H),!,readlist(T).
    readlist([]).
