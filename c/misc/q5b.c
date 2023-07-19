/*
Develop an iterative solution describing the relationship to judge whether the int d1[10]; has all the numbers in ascending order or not?
*/

#include <stdio.h>
int main()
{
	int d1[10],i ;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&d1[i]);//it is actuall address of ith element from array base
	}

	for(i=0;i<10-1;i++)
	{
		if(d1[i]>d1[i+1])// Element i and i+1 is accessed with *(d1+i) *(d1+i+1). Here, pointer arithmetic works element factor.
			break;
	}
	
	if(i==(10-1))
		printf("\n Yes, all the numbers are in ascending sorted order");
	else
		printf("\n No. not ascending sorted.");
	
	
}
