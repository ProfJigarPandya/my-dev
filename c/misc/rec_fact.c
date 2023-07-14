#include <stdio.h>
#include <conio.h>

long int factorial(int n)
{
    int fact;

    if(n==1)
	return 1;

    fact = n * factorial(n-1);

    return fact;
}


void main()
{
 int n=5;
 clrscr();

 printf("factorial of %d  is  %ld",n,factorial(n));

 getch();
}