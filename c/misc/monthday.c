/*
  AIM::   program for finding total months and remainig days
				from
		    total days entered from user

	Assumption: All months are of 30 days .....

						       BY JMP */


#include <stdio.h>
#include <conio.h>

 void main()
 {
	int totaldays,days,month;

	clrscr();

	printf("\n enter total days ");
	scanf("%d",&totaldays);

	/*  find month using  / operator */
	month = totaldays/30;

	/* find remaining days using % operator */
	days = totaldays%30;


	printf("month = %d  days = %d",month,days);

	getch();

 }


