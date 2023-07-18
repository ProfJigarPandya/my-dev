#include <stdio.h>
#define MAX 10
int* largest(int *ptr, int n);
int main()
{
	int arr[MAX]={12,3,4,5,2,3,5,78,3,2};
	int *pres;
	pres=largest(arr,MAX);
	printf("%d largest",*pres);

	return 0;
}

int* largest(int *ptr,int size)
{
	int *last=ptr+size;
	int *maxptr=ptr;
	int max=*maxptr;
	ptr++;
	while(ptr<last)
	{
		if(max<*ptr)
		{
			max=*ptr;
			maxptr=ptr;
		}
		ptr++;
	}
	return maxptr;
}
