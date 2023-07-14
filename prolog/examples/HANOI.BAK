  /****************************************************************/
  /*			TOWERS OF HANOI				  */
  /*			===============				  */
  /*		   this hanoi is slowed down			  */		  
  /* Call the predicate hanoi with the number of slices, you want.*/
  /* Example:  Hanoi(6).                                          */
  /****************************************************************/
DOMAINS
  TIME, ROW, COL, NUMBER = INTEGER

PREDICATES
  hanoi( NUMBER )
  move(  NUMBER, NUMBER, ROW, ROW, ROW, COL, COL, COL )
  inform(  NUMBER, NUMBER, ROW, ROW, COL, COL )
  makepole( NUMBER, NUMBER, COL)
  delay()  dd(TIME)
  move_vert(COL,NUMBER,ROW,ROW)
  move_horizon(ROW,NUMBER,COL,COL)

CLAUSES
  delay :- dd(10000).
  dd(0):-!.
  dd(N):-N1=N-1,dd(N1).

  hanoi(N) :-   
  	N<=13,!,
  	VB=2+6*N,VH=3+N,CV=N, CM=3*N, CH=5*N,
  	STCOL=(79-6*N)/2, STROW=(25-VH)/2,
	makewindow(1,7,7,"Hanoi",STROW,STCOL,VH,VB),
	makepole(N,N,CV),
	move(N,N,0,0,0,CV,CM,CH),
	cursor(0,0), write("Press any key"),readchar(_).

  hanoi(_):- write("maximum 13 disc's\n").

  move(H,1,HA,_,HC,CA,_,CH):-!,inform(H,1,HA,HC,CA,CH).
  move(H,N,HA,HB,HC,CA,CB,CC):-
		N1=N-1,
		HA1=HA+1,
		move(H,N1,HA1,HC,HB,CA,CC,CB),
		inform(H,N,HA,HC,CA,CC),
		HC1=HC+1,
		move(H,N1,HB,HA,HC1,CB,CA,CC).

 inform( H, N, H1, H2, C1, C2 ) :-
	C11=C1-N, C22=C2-N, NN=2*N,
	H11=H-H1, H22=H-H2,
	move_vert(C11,NN,H11,1),
	move_horizon(1,NN,C11,C22),
	move_vert(C22,NN,1,H22).


  makepole(_,0,_):-!.
  makepole(H,N,C):-HH=H-N,inform(H,N,HH,HH,C,C), N1=N-1, makepole(H,N1,C).


  move_vert(_,_,H,H):-!.
  move_vert(COL,SIZE,H1,H2):-H1<H2,!, /* move up */
	H11=H1+1,
	field_attr(H11,COL,SIZE,112),
	field_attr(H1,COL,SIZE,7),delay,delay,
	move_vert(COL,SIZE,H11,H2).
  move_vert(COL,SIZE,H1,H2):-H1>H2,!, /* move down */
	H11=H1-1,
	field_attr(H11,COL,SIZE,112),
	field_attr(H1,COL,SIZE,7),delay,delay,
	move_vert(COL,SIZE,H11,H2).

  move_horizon(_,_,H,H):-!.
  move_horizon(ROW,SIZE,C1,C2):-C1<C2,!, /* move right */
	C11=C1+1, HH=C1+SIZE,
	field_attr(ROW,HH,1,112),
	field_attr(ROW,C1,1,7),delay,
	move_horizon(ROW,SIZE,C11,C2).
  move_horizon(ROW,SIZE,C1,C2):-C1>C2,!, /* move left */
	C11=C1-1, HH=C11+SIZE,
	field_attr(ROW,C11,1,112),
	field_attr(ROW,HH,1,7),delay,
	move_horizon(ROW,SIZE,C11,C2).
circle

goal
  hanoi(10).