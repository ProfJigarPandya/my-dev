#include <stdio.h>
#include <conio.h>
void dispmult(int n,int count)
{
 int i;
 for(i=1;i<=count;i++)
 {
	printf("\n%d * %d = %d",n,i,n*i);
 }
}

void main()
{
 int no,count;
 clrscr();
 printf("\n Enter number to display multiplication column for it ..");
 scanf("%d",&no);
 printf("\n Enter number of rows  ..");
 scanf("%d",&count);

 dispmult(no,count);
 getch();
}
