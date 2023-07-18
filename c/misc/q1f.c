#include <stdio.h>
#define mymacro(x,y,type) type t; t=x; x=y; y=t;
void main()
{
	int a=2, b=3;
	mymacro(a,b,int);
	printf("%d %d",a,b);
}
