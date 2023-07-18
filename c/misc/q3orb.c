/*
Write a program to find out sum of digits using recursive function. For ex: if no = 123 then
ans = 1+2+3 = 6.*/
#include <stdio.h>

int sumofdigits(int n);

int main()
{
	int n;
	printf("\nEnter n");
	scanf("%d",&n);
	printf("\n Sum of digits of %d is %d", n , sumofdigits(n));
	return(0);
}

int sumofdigits(int n)
{
	if( (n%10) == n )
		return n;
	else
		return ( (n%10) + sumofdigits(n/10) );
}
