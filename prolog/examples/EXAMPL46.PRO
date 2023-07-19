               /* Program 46 */
domains
    charlist=char*
predicates
    string_chlist(string,charlist)
clauses
    string_chlist("",[]).
    string_chlist(S,[H|T]):-
        frontchar(S,H,S1),
        string_chlist(S1,T).
