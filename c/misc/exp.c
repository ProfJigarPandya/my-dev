/*
OR-Q3 A)Write a program to calculate exp(x,y) using recursive function(You have to find x^y eg. 2^4 that is 16)
*/

#include<stdio.h>
int power(int,int);
int main()
{
	int x,y,answer;
	printf("Enter x: ");
	scanf("%d",&x);
	printf("Enter y: ");
	scanf("%d",&y);
	answer=power(x,y);
	printf("exp(%d,%d) is %d\n",x,y,answer);
	return 0;
}
int power(int a,int b)
{
	if(b==0)
		return 1;
	else
	{
		return (a*power(a,b-1));
	}
}

