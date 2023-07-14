/* find factorial of n.....
	fact(n) = 1*2*3*.....*n
*/

#include <stdio.h>
#include <conio.h>

void main()
{
int n,i,fact;
clrscr();
printf("\n enter no. for finding factorial ");
scanf("%d",&n);

fact=1;
for(i=1;i<=n;i++)
{
	fact = fact * i;
}

printf("The factorial of %d is %d",n,fact);

getch();
}
