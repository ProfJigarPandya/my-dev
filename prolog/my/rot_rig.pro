
domains
 l=integer*
predicates
 fl(l,integer)
 ff(l,l)
 app(l,l,l)
 rr(l,l)
 
 
 clauses
 
 app([],L,L).
 app([He|L1],L2,[He|L3]):-app(L1,L2,L3).
 
 fl([Lastele],Lastele).
 fl([_|Tail],Last):-fl(Tail,Last).
 
 ff([Last],[]).
 ff([H|T],[H|Li2]):-ff(T,Li2).

 rr(Ll1,Rll1):-fl(Ll1,Laste),ff(Ll1,Slist),app([Laste],Slist,Rll1).
 