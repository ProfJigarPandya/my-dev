/* program 50*/
trace
predicates
   person(integer,symbol)
   rand_int_1_5(integer)
   rand_person(integer)
 goal
   clearwindow,
   rand_person(3).
clauses
   person(1,fred).
   person(2,tom).
   person(3,mary).
   person(4,dick).
   person(5,goerge).
   rand_int_1_5(X) :- random(Y),X=Y*5+1.
   rand_person(0):-!.
   rand_person(Count):-
      rand_int_1_5(N),person(N,Name),nl,nl,write(Name),nl,
      Newcount=Count-1,rand_person(NewCount).


