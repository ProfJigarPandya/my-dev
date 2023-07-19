#include <stdio.h>
#define n 1
int main()
{
	int x=1;
#if n == 1 
x=2;
#else
x=3;
#endif
	printf("%d",x);
	return(0);
}

