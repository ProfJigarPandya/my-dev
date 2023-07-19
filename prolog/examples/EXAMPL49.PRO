/* program 49 demonstrates findall */

domains
   name,address = string
   age =integer
   list =age*
predicates
   person(name,address,age)
   sumlist(list,age,integer)
goal
   findall(Age,Person(_,_,Age),L),sumlist(L,Sum,N),
   Ave=Sum/N,
   write("\n\nThis program finds the the average age from three lists with findall\nAverage =",Ave),nl,nl,nl.
clauses
   sumlist([],0,0).
   sumlist([H|T],Sum,N) :- sumlist(T,S1,N1),Sum=H+S1,N=1+N1.
   person("Sherlock Holmes","22B Baker Street",42).
   person("Pete Spier","Flat 22, 21st street",36).
   person("Mary Darrow","Flat 2, Omega House",51).   
      
   
   
     