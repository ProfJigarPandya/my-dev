                    /* Program 59 */

include "exampl58.pro"  /*excluding the goal*/
domains
    row,col,length=integer
    field=f(row,col,length)
    position=pos(row,col)
predicates
    scr(field,position,key)
goal
    Row=10,Col=10,Length=30,cursor(Row,Col),
    makewindow(1,23,1,"Example Editor",0,0,25,80),
    write("Edit the text. Use the arrow keys to move"),
    field_attr(Row,Col,Length,112),
    scr(f(Row,Col,Length),pos(Row,Col),home),nl,nl,
    field_str(Row,Col,Length,Contents),
    write("Edited contents: ",Contents).
clauses
    scr(_,_,esc):-!, fail.
    scr(_,_,fkey(10)):-!.
    scr(f(Row,Col,L),pos(R,C),char(Ch)):-
        scr_char(R,C,Ch),C1=C+1,C1<C+L,cursor(R,C1),
        readkey(Key), scr(f(Row,Col,L),pos(R,C1),Key).
    scr(f(Row,Col,L),pos(R,C),right):-
        C1=C+1,!,C1<C+L,cursor(R,C1),readkey(Key),
        scr(f(Row,Col,L),pos(R,C1),Key).
    scr(f(Row,Col,L),pos(R,C),left):-
        C1=C-1,C1>=Col,cursor(R,C1),
        readkey(Key),scr(f(Row,Col,L),pos(R,C1),Key).
    scr(Field,Pos,_):-
        beep,readkey(Key),scr(Field,Pos,Key).
