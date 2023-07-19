#include <stdio.h>
#include <conio.h>

void main()
{
	int x=10,y=20,z;
	clrscr();

	printf("\n%d",x<y); /* will have 1 value since true */

	printf("\n%d",x>y); /*will have 0 value since false */

	printf("\n%d",x+y<y);  /* arithmetic operators are having more
				precedence then relational operators....
				so x+y is evaluated first and it is related
				with y */

				/*	false so zero */

	x++;
	printf("\n%d",x);	/* x will have 11 value since
					incremented once */

	++x;
	x++;
	printf("\n%d",x); 	/* x have 13 since
					from 11 incremented twice */

	x=10;
	z=x++;			/* postfix ++ so, value assigned first
				then inceremented */
	x=10;		/*  so z will have 10 and x will go 11 */
	z=++x;
			/* prefix ++ */
			/* so incremented x is assigned so z is 11 and x is 11*/



	x=10;
	x+=20;		/* same as x = x +20; so , x is now 10+20 is 30*/

	x=10;
	y=20;
	z=30;
	printf("\n %d ",x<y && x<z); /* true AND true is true :::: logical AND */

	printf("\n %d ",x<y || x<z); /* true OR true is true :::: logical OR */


	x=10;
	y=20;
	printf("z =%d",x<y ? x : y); /* conditional operator */

	getch();



}