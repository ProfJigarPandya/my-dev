/*
 
 Pattern I
e.g. for n = 4 following pattern should be printed
*
**
***
****
 
 * */
#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n,r,c;
	scanf("%d",&n);
	for(r=1;r<n;r++)
	{
		for(c=1;c<=r;c++)
		{
			printf("*");
		}
		printf("\n");
	}

	//Print last row specially as we don't want newline afterwards.
	for(c=1;c<=r;c++)
	{
		printf("*");
	}
    return 0;
}
