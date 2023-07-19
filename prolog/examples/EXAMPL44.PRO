                /* Program 44 */

domains
    file = input
predicates
    start
    inspect_positions
goal
    start.
clauses
    start:-
        write("Which file do you want to work with ?"),
        readln(FileName),
        openread(input,FileName),
        inspect_positions.
    inspect_positions:-
        readdevice(keyboard),nl,write("Position No?"),  
        readreal(X),
        readdevice(input),filepos(input,X,0),readchar(Y),
        write(Y),inspect_positions.
