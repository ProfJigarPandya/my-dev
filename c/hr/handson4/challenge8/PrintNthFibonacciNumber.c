//Print nth Fibonacci number. Assume zeroth term is 0 itself and next.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n;
	int term0=0;
	int term1=1;
	int nextTerm;
	int i;
	scanf("%d",&n);
	if(n==0)
	{
		printf("%d",term0);
		return 0;
	}
	if(n==1)
	{
		printf("%d",term1);
		return 0;
	}

	for(i=2;i<=n;i++)
	{
		nextTerm = term0+term1;
		term0=term1;
		term1=nextTerm;
			
	}
	printf("%d",nextTerm);

    return 0;
}

