#include <stdio.h>
#include <conio.h>

void main()
{
int i,j,k;
clrscr();
for(i=1;i<=24;i++)
{
 if(i%2 == 0)
	k = 0;
 else
	k=1;
 for(j=1;j<=i;j++)
 {
   printf(" %d",k);
   k = (k==0) ? 1:0;
 }
   printf("\n");
}



getch();
}