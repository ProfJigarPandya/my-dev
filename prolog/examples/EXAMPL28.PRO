                       /* Program 28 */
domains
     monsters=integer*
predicates
    delay(integer)
    zapGun(integer,integer)
    delete(integer,monsters,monsters)
    testresult(monsters,integer)
    test(char,integer,integer)
    doit(integer,monsters,integer)
    showThem(monsters,integer,char)
goal
    makewindow(1,7,0,"",0,0,25,80),
    doit(56,[42,45,50,5,56,59,62],0).
clauses
    doit(Initial,Monsters,Row):-
        testresult(Monsters,Row),
        showThem(Monsters,Row,'\1'),
        readchar(Ch),
        test(Ch,Initial,Final),
        zapGun(24,Final),
        delete(Final,Monsters,LiveMonsters),
        NewRow=Row+1,
        cursor(24,Final),
        showThem(Monsters,Row,' '),
        doit(Final,LiveMonsters,NewRow).
    testresult([],_):-
        write("\nWell done champion zapper !"),
        delay(32000),exit.
    testresult(_,Row) :- Row<24,!.
    testresult(_,_) :-
        write("\nToo late, YOU have been zapped !"),
        delay(32000),exit.

    showThem([],_,_) :-!.
    showThem([Monster|TheRest],Row,Char) :-
          scr_char(Row,Monster,Char),
          showThem(TheRest,Row,Char).

    zapGun(N,C):-
          N>0,!,scr_char(N,C,'^'),delay(150),
          scr_char(N,C,' '),N1=N-1,zapGun(N1,C).
    zapGun(_,_).

    test('z',0,0):-!.
    test('x',79,79):-!.
    test('z',OldCol,NewCol):-!,NewCol=OldCol-1.
    test('x',OldCol,NewCol):-!,NewCol=OldCol+1.
    test(_,C,C).

    delete(_,[],[]).
    delete(X,[X|R],R):-!.
    delete(X,[Y|R],[Y|R2]) :- !,delete(X,R,R2).

    delay(N):-N>0,!,N1=N-1,delay(N1).
    delay(0).
