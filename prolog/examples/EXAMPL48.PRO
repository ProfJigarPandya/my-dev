              /* Program 48 */
domains
    tok = numb(integer);char(char);name(string)
    tokl = tok*
predicates
    scanner(string,tokl)
    maketok(string,tok)
clauses
    scanner("",[]).
    scanner(Str,[Tok|Rest]):-
        fronttoken(Str,Sym,Str1),
        maketok(Sym,Tok),
        scanner(Str1,Rest).
    maketok(S,name(S)):- isname(S).
    maketok(S,numb(N)):- str_int(S,N).
    maketok(S,char(C)):- str_Char(S,C).

