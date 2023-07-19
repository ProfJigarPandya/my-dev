#include <stdio.h>
#include <conio.h>
double power(int x,int y)
{
	double result;
	result  = 1.0;
	if(y>=0)  // x to the power y where y is positive
	{
	    while(y--)
		 result *= x;
	}
	else  // y is negative
	{
	   while(y++)
		result/=x;

	}

	return result;
}


void main()
{
int m=3,n=4;

clrscr();

printf(" \n power m to the n is %12f ",power(m,n));

getch();
}