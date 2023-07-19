     /* program 62 */

 domains
   tree =reference t(id,val,tree,tree)
   id   = symbol
   val  = integer
 predicates
   lookup(id,val,tree)
 clauses
   lookup(ID,VAL,t(ID,VAL,_,_)):- !.
   lookup(ID,VAL,t(IDI,_,TREE,_)):-
       ID<IDI,!,
       LOOKUP(ID,VAL,TREE).
   lookup(ID,VAL,t(_,_,_,TREE)):-
       lookup(ID,VAL,TREE).
       
       
       