#include <stdio.h>
int main()
{
	int x,y;
	int i,j;
	//int *p1=4;
	//int *p2=2;
	//int *p1=&i,*p2=&j;//Note that we can not do directly *p1=4 unless p1 is pointing to a writable memory area. Hence, here i is created. Same with p2 and j.
	*p1=4;
	*p2=2;
	x=*p1*-*p2/4+5;
	y=3**p1+*p2++;
	printf("\n x is %d ",x);
	printf("\n y is %d ",y);
}
