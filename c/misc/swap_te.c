     /* interchange of two integers using temp variable*/

#include <stdio.h>
#include <conio.h>


void main()
{
	int no1,no2;
	int temp;

	clrscr();

	no1=50;
	no2=100;

	/* interchange of two nu */

	temp = no1;
	no1 = no2;
	no2 = temp;

	/**********************/

	printf("\n no1 is %d ",no1);
	printf("\n no2 is %d ",no2);

	getch();

}
