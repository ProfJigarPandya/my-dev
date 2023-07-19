                /* Program 27 */
predicates
    start
    run(integer)
    do_sums
    set_up_windows
    clear_windows
clauses
  start :-
         set_up_windows,do_sums.
  set_up_windows :-
       makewindow(1,7,7,"",0,0,25,80),
       makewindow(1,7,7,"Left operand",2,5,5,25),
       makewindow(2,7,7,"",2,35,5,10),
       nl,write(" PLUS"),
       makewindow(2,7,7,"Right operand",2,50,5,25),
       makewindow(3,7,7,"Gives", 10,30,5,25),
       makewindow(4,7,7,"",20,30,5,35).
  do_sums :-
         run(_),clear_windows,do_sums.
  run(Z)  :-
       shiftwindow(1),
       cursor(2,1),readint(X),
       shiftwindow(2),
       cursor(2,10),readint(Y),
       shiftwindow(3),Z=X+Y,cursor(2,10),write(Z),
       shiftwindow(4),
       write("  Please press the space bar"),
       readchar(_).
  clear_windows :-
       shiftwindow(1),clearwindow,
       shiftwindow(2),clearwindow,
       shiftwindow(3),clearwindow,
       shiftwindow(4),clearwindow.
