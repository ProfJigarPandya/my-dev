/*
Write program to solve the series: 1/1! + (3)3/3! + (5)5/5! + (7)7/7! + (9)9/9! [6]
+………. .+ (n)n/n! . Where n is entered by user.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n,
		p,
		f=1,
		i;
	float result=1.0;
		
	printf("\n Enter odd number n for the series ");
	scanf("%d",&n);
	
	if( (n%2) == 0 )
	{
		printf("\n Enter odd number for the series. ");
		exit(1);
	}
	for(i=3;i<=n;i+=2)
	{	
		p = pow(i,i);
		f = f * (i-1) * i;
	
		result = result +  ((float) p / f);
		printf("%d/%d + ",p,f);
	}
	
	printf("\nSeries result for %d is %f ",n,result);
}
