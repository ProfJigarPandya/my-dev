#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long factorial(int);

int main()
{

    int n;
  	long fact;
  
  	scanf("%d", &n);
  	fact = factorial(n);
  	printf("%ld", fact);
  
    return 0;
}

long factorial(int n)
{
  	/* remove this comment and write your code here */
	long result=1;
	for(int i=2;i<=n;i++)
		result=result*i;
	return result;
}
