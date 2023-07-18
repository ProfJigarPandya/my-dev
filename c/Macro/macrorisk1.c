#include <stdio.h>
#define p 5
int main()
{
	int arr[p], sum=0, i;
	
	printf("\n Array content ");
	for(i=0;i<p;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	
	}
	
	printf("\n sum is %d ",sum);
}
