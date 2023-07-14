                /* Program 41 */
predicates
    piano
    tone(char,integer)
goal
    piano.
clauses
    piano:-
        readchar(Note),tone(Note,Freq),sound(5,Freq),piano.

    tone('a',131).  tone('w',139).  tone('s',147).
    tone('d',165).  tone('e',156).  tone('f',175). 
    tone('t',185).  tone('g',196).  tone('y',208).  
    tone('h',220).  tone('u',233).  tone('j',247).  
    tone('k',262).
    tone(_,5000). /*all other keys squeak */
