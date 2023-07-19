               /* Program 43 */
domains
    file = myfile
predicates
    start
    readin(char)
goal
   start.    
clauses
    start:-
        write("this program reads your input and writes it to tryfile.one\n"),
        openwrite(myfile,"tryfile.one"),
        writedevice(myfile),
        readchar(X),
        readin(X),
        closefile(myfile),
        writedevice(screen),
        write("Your input has been transferred a file").
    readin( '#' ):-!.
    readin('\13'):-!,write("\13\10"),readchar(X),readin(X).
    readin(  X  ):- write(X),readchar(Y),readin(Y).
