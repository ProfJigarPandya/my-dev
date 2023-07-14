#include <stdio.h>
#include <conio.h>
void main()
{
   int row,n,i;
   clrscr();
   printf("\n Enter no.of rows ");
   scanf("%d",&n);
   for(row=1;row<=n;row++)
   {
	for(i=1;i<=row;i++)
	{
		printf(" %d ",i*i);
	}
	printf("\n");
   }
   getch();
}
