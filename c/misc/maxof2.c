/* find maximum of two numbers */

#include <stdio.h>
#include <conio.h>
void main()
{
       int no1,no2;
       clrscr();

       printf("enter no1. ");
       scanf("%d",&no1);

       printf("enter no2. ");
       scanf("%d",&no2);

       if(no1>no2)
       {
	  printf("\nMaximum is %d",no1);
       }
       else
       {
	  printf("\n MAximum is %d",no2);
       }

       printf("\nhave a nice day");

       getch();

}