//Error or Output
#include <stdio.h>
void main()
{ 
	int i;
	for (i=0;i<3;i++)
		mul();
}
void mul()
{ 
	static int n;
	printf("%d",n);
	n *= 5;
}
