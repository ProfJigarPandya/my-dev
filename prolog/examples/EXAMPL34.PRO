               /* Program 34 */
predicates
/*   move(char,integer,integer,integer,integer)*/
   start
/*   changestate(integer,integer)*/
goal
   start.
clauses
   start:-
   		detectgraph(Gd,Gm),
   		initgraph(Gd,Gm,Md,Mn,"d:\\tc\\bgi").
/*       graphics(1,1,4),
       line(1000,1000,1000,31000,2),
       line(1000,31000,31000,31000,2),
       line(31000,31000,31000,1000,2),
       line(31000,1000,1000,1000,2),
       changestate(15000,15000).
   changestate(X,Y):-
        readchar(Z),move(Z,X,Y,X1,Y1),changestate(X1,Y1).
   move('r',X,31000,X,31000):- !.
   move('r',X,Yold,X,Ynew):- !,Ynew=Yold+100,dot(X,Yold,3).
   move('l',X,1000,X,1000):- !.
   move('l',X,Yold,X,Ynew):- !,Ynew=Yold-100,dot(X,Yold,3).
   move('u',1000,Y,1000,Y):- !.
   move('u',Xold,Y,Xnew,Y):- !,Xnew=Xold-100,dot(Xold,Y,3).
   move('d',31000,Y,31000,Y):- !.
   move('d',Xold,Y,Xnew,Y):- !,Xnew=Xold+100,dot(Xold,Y,3).
   move('*',_,_,_,_):- !,exit.
   move(_,X,Y,X,Y).
*/