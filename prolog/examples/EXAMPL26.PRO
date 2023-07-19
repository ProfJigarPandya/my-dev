                /* Program 26 */
predicates
    run
clauses
    run :-
      makewindow(1,7,7,"A blue window",2,5,10,50),
      write("The characters are red"),
      makewindow(2,7,7,"A light cyan window",14,25,10,40),
      write("This window is light cyan and the "),
        write("letters are black and blink."),
        write("  Please type an integer to exit."),nl,
        readint(_),
        removewindow,
        write("    Please type an integer to exit."),nl,
        readint(_),
        removewindow.