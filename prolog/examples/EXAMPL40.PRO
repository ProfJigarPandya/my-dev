                /* Program 40 */
domains
    list=integer*
predicates
    spotlight(integer,integer,integer)
    xy(list)
    undo
goal
    graphics(2,0,1),
    makewindow(1,7,7,"First",1,1,18,70),
    xy([0,0,0,6000,4000,20500,20000,24000,16100,1000]),
    xy([0,0,0,9000,3000,26500,20100,24400,20100,1000]),
  
    makewindow(2,7,7,"Second",10,20,14,60),
    xy([0,1000,0,9000,0,20000,15000,20000,15000,1000]),
    makewindow(3,7,7,"Text",15,0,6,35),
    write(""),nl,
    write("Turbo Prolog window & graphics."),
    undo,undo,undo.
clauses
    xy([X,Y|Rest]):-
        spotlight(15,X,Y),!,xy(Rest).
    xy(_).
     spotlight(0,_,_):-!.
     spotlight(N,R,C):-
        X=N*1200,line(R,C,9000,X,1),N1=N-1,
        spotlight(N1,R,C).
     undo:-
        write("\n\nPress the space bar"),
        readchar(_),removewindow.
