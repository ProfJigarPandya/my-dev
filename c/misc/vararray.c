/*
Variable-length automatic arrays are allowed in ISO C99, and as an extension GCC accepts them in C90 mode and in C++. These arrays are declared like any other automatic arrays, but with a length that is not a constant expression. The storage is allocated at the point of declaration and deallocated when the block scope containing the declaration exits.

*/

#include <stdio.h>
int main()
{	
	int n,i;

	scanf("%d",&n);
	int arr[n];

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}

	return 0;
}
