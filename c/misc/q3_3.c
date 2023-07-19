#include <stdio.h>
int main()
{
	int *x();
	int (*y)();
	int arr[10]={11,2,3,4,5,6,7,8,9,10};
	int *ptr=arr;
	printf("\n%d",++*ptr);//12
	printf("\n%d",*++ptr);//2
	
}
