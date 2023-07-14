              /* Program 29 */
domains
    list=symbol*
    scores=integer
predicates
    member(symbol,list)
    run
    continue(list,scores)
    yes_no_count(symbol,list)
    guessword(scores,list)
    word(list,integer)
    read_as_list(list,integer)
goal
    makewindow(1,7,0,"",0,0,25,80),
    makewindow(2,7,135,"Counting",1,20,4,34),
    makewindow(3,112,112,"YES",5,5,7,30),
    makewindow(4,112,112,"NO",5,40,7,30),
    makewindow(5,7,7,"",14,20,10,34),
    run.
clauses
    run:- word(W,L),
          shiftwindow(1),clearwindow,
          write("The word has ",L," letters"),
          shiftwindow(2),clearwindow,
          shiftwindow(3),clearwindow,
          shiftwindow(4),clearwindow,
          continue(W,0),fail.
    continue(L,R):-
          shiftwindow(5),clearwindow,
          write("Guess a letter :"),
          Total=R+1,readln(T),yes_no_count(T,L),
          shiftwindow(5),clearwindow,
          guessword(Total,L),continue(L,Total).
    yes_no_count(X,List):-
          member(X,List),shiftwindow(3),write(X),
                         shiftwindow(2),write(X),!.
    yes_no_count(X,_):-
           shiftwindow(4),write(X),
           shiftwindow(2),write(X).
    guessword(Count,Word):-
           write("Know the word yet? Press y or n"),
           readchar(A),A='y',cursor(0,0),
           write("Type it in one letter per line \n"),
           word(Word,L),read_as_list(G,L),
           G=Word,clearwindow,window_attr(112),
           write("Right! You used ",Count," guess(es)"),
           readchar(_),window_attr(7),!,fail.
    guessword(_,_).
    word([b,i,r,d],4). word([p,r,o,l,o,g],6).
    word([f,u,t,u,r,e],6).
    member(X,[X|_]):-!.
    member(X,[_|T]):-member(X,T).
    read_as_list([],0) :-!.
    read_as_list([Ch|Rest],L) :-
           readln(Ch),L1=L-1,read_as_list(Rest,L1).