#include<stdio.h>
#include<conio.h>

void main()
{
 int x=1,i,n;
 clrscr();

 printf("Enter how many rows:");
 scanf("%d",&n);
 printf("\n\t ORIGINAL \t CUBE(x*x*x) ");
 for(i=0;i<n;i++)
  {
   printf("\n\t %d \t\t %4d",x,x*x*x);
   x++;
  }
 getch();
}