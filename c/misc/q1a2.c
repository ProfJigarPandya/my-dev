#include <stdio.h>
int main()
{
	int a=4;
	int b=2;
	int *p1=&a, *p2=&b;
	int x, y;
	x=*p1 * - *p2 /4 +5;
	y=3**p1+*p2;
	printf("\n x is %d",x);
	printf("\n y is %d",y);
}
