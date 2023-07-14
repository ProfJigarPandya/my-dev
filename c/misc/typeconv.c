/*

 sum =    1 + 1/2 + 1/3 + .... + 1/10

*/

#include <stdio.h>
#include <conio.h>

void main()
{
	float sum;
	int n;

	clrscr();

	sum = 0.0;

	for(n =1; n<=10; ++n)
	{
		sum = sum+ 1/n;     // if u do not write (float) than..?
		printf("\t%2d\t%6.4f\n",n,sum);
	}

	getch();
///        sum = sum+ 1/(float)n;     // if u do not write (float) than..?
}