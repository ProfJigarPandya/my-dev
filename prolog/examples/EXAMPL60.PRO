                 /* Program 60 */
predicates
  wait(char)
  equal(char,char)
  test(string)
goal
  makewindow(3,7,0,"",0,0,25,80),
  makewindow(2,7,7,"Key to press now",2,5,6,70),
  makewindow(1,7,7,"Accepted letters",8,10,10,60),
  Word = "Peter Piper picked a peck of pickled peppers",
  write("Please type :\n\t",Word,"\n\t"),
  time(0,0,0,0),test(Word),
  time(_,_,S,H),
  write("\nYou took ",S," seconds and ",H," hundredths").
clauses
  wait(X):- inkey(Y),equal(X,Y).
  wait(X):- shiftwindow(2),write(X),wait(X).
  test(W):- frontchar(W,Ch,R),wait(Ch),
            shiftwindow(2),write(Ch),test(R).
  test("").
  equal(X,X):-!.
  equal(_,_):-beep,fail.
