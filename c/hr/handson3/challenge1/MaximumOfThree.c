//Read three numbers n1,n2,n3 from user and print maximum number from it.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n1,n2,n3;
	int max;
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);

	if(n1>n2)
	{
		max = n1;
	}
	else
	{
		max=n2;
	}

	if(n3>max)
	{
		max = n3;
	}
	printf("%d",max);

    return 0;
}

