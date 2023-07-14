/*  Q-3(a)
  write a program which generates cube table with heading like below

  ORIGINAL		CUBE(X*X*X)
   1			  1
   2			  8
   3			 27
   4			 64
   5			125

   take care for formatted display the number of rows of the
   table should be as per user requirement

*/

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