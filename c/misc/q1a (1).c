/*
 *Write a recursive function to compute exp(x,y). (i.e:exp(x,y)=x^y=2^3=8).
 */
#include <stdio.h>

int myexp(int x, int y);
int main()
{
	printf("Result of exp(%d,%d) is %d",2,3,myexp(2,3));
	return(0);
}
/* For y>=1.
 */
int myexp(int x, int y)
{
	if(y==1)
		return x;
	else
		return (x*myexp(x,y-1));
}
