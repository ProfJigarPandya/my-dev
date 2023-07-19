#include<stdio.h>
int main()
{
	int x=10, y=20;
	
	int *p1=&x, *p2=&y;

	/*int b=5*-*p2/*p1;*/
	int b=5*-*p2/(*p1);

	printf("\n b is %d ",b);

	//int *p=&a, a;
	int a=70,*p=&a;
	printf("\n a is %d",*p);
}
