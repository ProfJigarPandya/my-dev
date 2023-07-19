                   /* Program 58 */
domains
    key = cr;esc;break;tab;btab;del;bdel;ins;end;home;
          fkey(integer);up;down;left;right;char(CHAR);other
predicates
    readkey(key)
    key_code(key,char,integer)
    key_code2(key,integer)
goal
    write("Keyboard test. Press a key!"),
    readkey(Key),
    write("The ",Key,"-key was pressed").
clauses
    readkey(Key):-
        readchar(T),char_int(T,Val),key_code(Key,T,Val).

    key_code(Key,_,0):-
        readchar(T),char_int(T,Val),key_code2(Key,Val),!.
    key_code(break,_,3):-!.      key_code(bdel,_,8):-!.
    key_code(tab,_,10):-!.       key_code(cr,_,13):-!.
    key_code(esc,_,27):-!.       key_code(char(T),T,_).

    key_code2(btab,15):-!.       key_code2(home,71):-!.
    key_code2(up,72):-!.         key_code2(left,75):-!.
    key_code2(right,77):-!.      key_code2(end,79):-!.
    key_code2(down,80):-!.       key_code2(ins,82):-!.
    key_code2(del,83):-!.
    key_code2(fkey(N),V):- V>58, V<70, N=V-58, !.
    key_code2(other,_).
