/* member([jigar,nilesh,dhaval],nilesh) == yes
   member(                     ,ddd) ==no */
domains
  list = symbol*
predicates
  member(list,symbol)   
clauses
  member([ ],Name):-fail.	 
  member([H|T],Name):-H=Name.
  member([H|T],Name):-H<>Name,member(T,Name).
  	