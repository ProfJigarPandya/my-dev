/* find maximum of two numbers */

#include <stdio.h>
#include <conio.h>
void main()
{
       int no1,no2,no3;
       clrscr();

       printf("enter no1. ");
       scanf("%d",&no1);

       printf("enter no2. ");
       scanf("%d",&no2);

       printf("enter no3. ");
       scanf("%d",&no3);

       if(no1>no2)
       {
		if(no1>no3)
		{
		   printf("\nMaximum is %d",no1);
		}
		else
		{
			printf("\n maximum is %d",no3);
		}
       }
       else
       {
		if(no2>no3)
		{
			printf("\nMaximum is %d",no2);
		}
		else
		{
			printf("\n maximum is %d",no3);
		}

       }

       printf("\nhave a nice day");

       getch();

}