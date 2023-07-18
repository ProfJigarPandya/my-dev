//Smart factorial
/*

Write a program to solve the series using user defined functions: 1 / 1! + (3)^3 / 3! +
(5)^5 / 5! + ... + (n)^n / n!. Here, n is a positive integer entered by user. Extend the
factorial function to behave smart-fully.

Learning internal static variables.

*/

#include <stdio.h>
#include <math.h>

int smartfact(int n)
{
	//See because of internal static variables, this function retains previous call f and p values and continues from that point onward multiplication.

	static int f=1;
	static int p=1;

	printf("\nSmart Factorial of %d started from %d ",n,p);

	while(p<=n)
	{
		f = f * p;
		p++;
	}

	printf ("   %d ",f);
	return f;
}

int fact(int n)
{
	int f=1;
	int p=1;

	printf("\nFactorial of %d started from %d ",n,p);

	while(p<=n)
	{
		f = f * p;
		p++;
	}
	
	printf ("   %d ",f);
	return f;
}
int main()
{
	int n;

	float result=1.0;

	int p;
	int f;
	int i;

	printf("\nEnter n for finding how many terms of sin series be evaluated for. ");
	scanf("%d",&n);
	

	
	for(i=3;i<=n;i+=2)
	{
		p = pow(i,i);
		f = fact(i);		
		result = result +( (float) p / f ); 
	}



	printf("\n Result using normal factorial %f" ,result);	


	result=1.0;
	for(i=3;i<=n;i+=2)
	{
		p = pow(i,i);
		f = smartfact(i);		
		result = result +( (float) p / f ); 
	}
	
	printf("\n Result using smart factorial %f" ,result);	
}
