#include <stdio.h>
#include <conio.h>
void main()
{
 int n;
 long int sum;

 clrscr();
 sum=0;
 for(n=1;n<=200;n++)
 {
	sum = sum + n * n;
	printf("\nsum of square %d is %ld ",n,sum);
 }

 getch();
}