#include <stdio.h>
int main()
{
	int *p, a[5]={1,2,3,4,5};
	p=a;
	while(p<&a[4])
	{
		printf("%d %d\n",*p,*p++);
	}
	return 0;
}

