#include <stdio.h>
int main()
{
	int *a[5];
	int (*b)[5];
	printf("\n Sizeof a is %d",sizeof(a)); //Array of pointers
	printf("\n Sizeof b is %d",sizeof(b)); //Pointer to arrays of size 5 int
}
