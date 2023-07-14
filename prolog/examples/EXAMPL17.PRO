               /* Program  17*/
domains
  d = pair(integer,integer) ; single(integer) ; none
predicates
     equal(d,d)
clauses
     equal(X,X).
     equal(single(4),pair(3,4)).
     equal(pair(2,1),pair(2,1)).
     equal(none,none).
     