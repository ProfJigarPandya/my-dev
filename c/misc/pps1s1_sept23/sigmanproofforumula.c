#include <stdio.h>
/*
Develop a C program to prove the shown mathematical formula’s correctness. Note that the program must keep asking for input n till when the natural number is NOT entered by the user. Find both results for valid input. Prove the formula’s correctness.

Summation of first n natural numbers is the result of series
             1+2+3+4+5+...+n, 
  where n is nth natural number.

sigma(n) => n*(n+1)/2
*/

int main()
{
	int n;
	long int resultEq=0, resultLoop=0;
	int i;

	do
	{
		printf("\nEnter natural number as input to prove the formula");
		scanf("%d",&n);
	}while(n<=0);
	

	//Let's find out result of formula
	resultEq= (n *((long int)n+1) )/2;

	//Let's find out result using a loop
	for(i=1;i<=n;i++)
	{
		resultLoop+=i;		
	}

	if(resultEq==resultLoop)
	{
		printf("\nFormula is correct\n");
		printf("\nFormula based addition %ld",resultEq);
		printf("\nManually loop based addition %ld",resultLoop);
	}
	else
	{
		printf("\nFormula is NOT correct\n");
	}
	return 0;

}
