   /* program 52 */
 domains
   town     =symbol
   distance =integer 
 predicates
   road(town,town,distance)
   route(town,town,distance)
 clauses
   road(tampa,houston,20).
   road(gordon,tampa,30).
   road(houston,gordon,10).
   road(houston,kansas_city,12).
   road(gordon,kansas_city,13).
   
   route(Town1,Town2,Distance):-
       road(Town1,Town2,Distance).
   route(Town1,Town2,Distance):-
       road(Town1,X,Dist1),
       route(X,Town2,Dist2),
       Distance=Dist1+Dist2,!.
  
       