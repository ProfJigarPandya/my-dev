//Print an integer array in reverse
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n,i;
	scanf("%d",&n);
	int data[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	for(i=n-1;i>0;i--)
	{
		printf("%d ",data[i]);
	}
	printf("%d",data[i]);
	
    return 0;
}

