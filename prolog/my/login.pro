domains
	name,password=symbol
predicates
	go
	user(name,password)
	check(name,password)
clauses
	user(san,saa).	
	user(na,pa).
	user(me,rd).
	user(am,ps).
	check(Name,Password):-
             user(Name,Password).
        go:-write("Enter your name"),nl,
            readln(Name),write("Enter password"),nl,
            readln(Password),            
             check(Name,Password),
             user(Name,Password),        
	     write("You have logged in!").
	go:- write("You have not enough permission"),fail.
        
