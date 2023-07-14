
     
     
               /* Program 32 */
predicates
	delay(integer)               
goal
     makewindow(1,15,15,"Timer",0,0,20,40),
     time(0,0,0,0),system("dir c:"),
      time(H,M,S,Hundredths),
     write(H," hours  "),
     write(M," minutes  "),
     write(S," seconds  "),
     write(Hundredths," hundredths of a second"),nl,nl,nl,
clauses
   delay(32000).     
   delay(N):-N>0,!,N1=N-1,delay(N1).
     
