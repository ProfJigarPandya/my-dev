     /* interchange of two integers
		without using temp variable*/

#include <stdio.h>
#include <conio.h>


void main()
{
	int no1,no2;


	clrscr();

	no1=50;
	no2=100;

	/* interchange of two nu */

	no1 = no1 + no2;
	no2 = no1 - no2;
	no1 = no1 - no2;

	/**********************/

	printf("\n no1 is %d ",no1);
	printf("\n no2 is %d ",no2);

	getch();

}
