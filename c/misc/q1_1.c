#include <stdio.h>
int main()
{
	int *a[5];//This is array of pointers
	printf("\n Size allocated to a in bytes %d",sizeof(a));

	int (*b)[5];//This is pointer to array
	printf("\n Size allocated to b in bytes %d",sizeof(b));
	
	printf("\n In linux gcc with 32 bit architecture computer i386, pointer size is %d ", sizeof(void *));
}

