              /* Program 23 */
domains
    person      = p(name,age,telno,job)
    age         = integer
    telno ,name,job = string
predicates
    readperson(person)
    run
goal
    run.
clauses
    readperson(p(Name,Age,Telno,Job)):-
        write("Which name ? "),readln(Name),
        write("Job ?"),readln(Job),
        write("Age ?"),readint(Age),
        write("Telephone no ?"),readln(Telno).
    run:-
        readperson(P),nl,write(P),nl,nl,
        write("Is this compound object OK (y/n)"),
        readchar(Ch),Ch='y'.
    run:-
        nl,nl,write("Alright, try again"),nl,nl,run.
