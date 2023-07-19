#include <stdio.h>
#include <conio.h>
void main()
{
 int arr[10],i;
 int max_roll,max_val,min_roll,min_val;

 clrscr();
 for(i=0;i<10;i++)
	scanf("%d",&arr[i]);

 max_val = arr[0];
 max_roll = 0;

 for(i=1;i<10;i++)
 {
   if(max_val < arr[i])
   {
	max_val = arr[i];
	max_roll = i;
   }
 }

 printf("\n Result \n Student roll_no        marks ");
 for(i=0;i<10;i++)
	printf("\n %2d \t\t\t %4d",i,arr[i]);

 printf("\n Maximum marks %d is of %d roll call",arr[max_roll],max_roll);
 getch();
}
