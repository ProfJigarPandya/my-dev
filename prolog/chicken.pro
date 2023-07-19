nowarnings

domains
list=symbol*

predicates
eat(symbol,symbol)
checkeat(list)
search(symbol,list)
move(list,list,list,list)
moveback(list,list,list,list)
select(symbol,symbol,list)
deletelist(list,list,list)
appendlist(list,list,list)
selectone(list,list)
goone(list,list)
go

clauses
eat(fox,chicken).
eat(chicken,fox).
eat(chicken,grain).
eat(grain,chicken).
checkeat(L):-!,not(search(farmer,L)).
checkeat([H1|[H2|T]]):-eat(H1,H2),!.
checkeat([H1|[H2|T]]):-checkeat([H1|T]),!.
checkeat([H1|[H2|T]]):-checkeat([H2|T]).
search(H,[H|T]).
search(X,[H|T]):-search(X,T).
move(Left,Right,L,R) :- select(X,Y,Left),deletelist([X,Y],Left,L),
                    appendlist([X,Y],Right,R).
moveback(Left,Right,L,R):-selectone(Moving,Right),deletelist(Moving,Right,R),
		      appendlist(Moving,Left,L).
go:-goone([farmer,fox,chicken,grain],[]).
goone([],Right).
goone(Left,Right):-move(Left,Right,L,R),moveback(L,R,L1,R1),goone(L1,R1).

select(farmer,chicken,List):-getlength(List,I),I=4,!.
select(farmer,chicken,List):-getlength(List,I),I=2,!.
select(farmer,grain,List):-absent(Z,List),Z=fox,!.
select(farmer,fox,List):-absent(Z,List),Z=grain,!.
select(farmer,fox,List).
select(farmer,grain,List)./*alternative solution*/

selectone([farmer],List):-getlength(List,I),I=2,!.
selectone([farmer],List):-absent(chicken,List),!.
selectone([farmer,chicken],List):-absent(fox,List),!.
selectone([farmer,chicken],List).
selectone([farmer,fox],List)./*alternative solution*/
