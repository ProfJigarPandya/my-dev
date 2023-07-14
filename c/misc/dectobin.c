/* convert decimal to binary... */

#include <stdio.h>
#include <conio.h>


void main()
{
 int x=45;
 clrscr();

 while(x>=1)
 {
	printf("%d",x%2);
	x=x/2;
 }
 getch();
}