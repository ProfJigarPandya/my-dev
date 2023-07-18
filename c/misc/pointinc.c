#include <stdio.h>
int main()
{
	int x=10, y=10;
	int *p1 = &x;
	int *p2	= &y;

	printf("\n%d",(*p1)++);
	printf("\n%d",--(*p2));
	printf("\n%d",*p1+(*p2)--);
	printf("\n%d",++(*p2)-*p1);
	
	
}
