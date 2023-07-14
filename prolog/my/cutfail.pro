trace
predicates
 a(integer)
 b(integer)
 c(integer)
 d(integer)
 
clauses
 a(X):-!,b(X).
 a(0).
 a(1).
 b(X):-c(X).
 b(2).
 b(3).
 c(X):-d(X),!.
 c(4).
 c(5).
 d(6).
 d(7).
 