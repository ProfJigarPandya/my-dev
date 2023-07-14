               /* Program 16 */
domains
    name,sex,interest = symbol
    interests = interest*

predicates
    findpairs
    person(name,sex,interests)
    member(interest,interests)
    common_interest(interests,interests,interest)
clauses
    findpairs if person(Man, m, ILIST1 ) and
          person( Woman, f, ILIST2 ) and
          common_interest( ILIST1, ILIST2, _ ) and

          write( Man, " might like  ",Woman ) and nl and
          fail.
     findpairs:- write ("-----------end of the 1ist---").

     common_interest( IL1, IL2, X ) if
           member(X, IL1 ) and member(X, IL2) and !.

     person(tom,m,[travel,books,baseball]).
     person(mary,f,[wine,books,swimming]).

     member( X, [X|_] ).
     member( X, [_|L] ) if member( X, L ).
