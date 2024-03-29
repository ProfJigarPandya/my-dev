                  /* Program 57 */
             
domains
    queen = q(integer,integer)
    queens=queen*
    freelist = integer*
    board=board(queens,freelist,freelist,freelist,freelist)
predicates
    placeN(integer,board,board)
    place_a_queen(integer,board,board)
    nqueens(integer)
    makelist(integer,freelist)
    findandremove(integer,freelist,freelist)
clauses
    nqueens(N):-
        makelist(N,L),Diagonal=N*2-1,makelist(Diagonal,LL),
        placeN(N,board([],L,L,LL,LL),Final),write(Final).

    placeN(_,board(D,[],[],D1,D2),board(D,[],[],D1,D2)):-!.
    placeN(N,Board1,Result):-
        place_a_queen(N,Board1,Board2),
        placeN(N,Board2,Result).

    place_a_queen(N,board(Queens,Rows,Columns,Diag1,Diag2),
            board([q(R,C)|Queens],NewR,NewC,NewD1,NewD2)):-
        findandremove(R,Rows,NewR),
        findandremove(C!��2$�$��]��B<,����! 2(�h�E I�Y�D  D��� L��K"  �$H>��>�>A�$`�%��@1�0�   s8�30A��2 8�H���@1�0�   px0 p0�t],Rest).
   findandremove(X,[Y|Rest],[Y|Tail]):-
        findandremove(X,Rest,Tail).

   makelist(1,[1]).
   makelist(N,[N|Rest]):-
        N>0,N1=N-1,makelist(N1,Rest).
