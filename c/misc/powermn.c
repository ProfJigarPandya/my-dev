/* program to evaluate m to the power of n

	      n
	y = m	is same as m * m * m ...... .n times

	where n is non-negative integer

*/
#include <stdio.h>
#include <conio.h>

void main()
{
int count;
float y;
float m;int n;


clrscr();
printf("\n enter m and n to find power m,n ");
scanf("%f%d",&m,&n);

count=1;
y=1;
while(count<=n)
{
	y = y * m;
	count++;
}

printf("\n power is  %f",y);

getch();
}
