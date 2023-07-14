domains
 l = integer*
predicates
 listwolast(l,l)
clauses
 listwolast([Last],[]).
 listwolast([H|T],[H|L]):-listwolast(T,L). 
 