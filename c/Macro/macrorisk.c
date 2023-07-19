#include <stdio.h>
#define SQUARE(a) a*a
#define SSQUARE(a) ((a)*(a))
int main()
{
	printf("\n square of 5 is %d",SQUARE(5));
	printf("\n square of 5+5 is %d",SQUARE(5+5));
	printf("\n square of 5 is %d using smart square",SSQUARE(5));
	printf("\n square of 5+5 is %d using smart square",SSQUARE(5+5));
	
}
