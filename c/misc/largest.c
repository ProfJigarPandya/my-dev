#include <stdio.h>
#include <conio.h>

int largest(int list[],int n)
{
 int maximum;
 int i;
 maximum = list[0];

 for(i=1;i<n;i++)
 {
	if(maximum<list[i])
		maximum = list[i];
 }

 return maximum;
}

void main()
{
 int arr[10];
 int max,i;
 clrscr();

 printf("\n Enter ten numbers ");
 for(i=0;i<10;i++)
	 scanf("%d",&arr[i]);

 max = largest(arr,10);

 printf("\n Maximum is  %d",max);
 getch();
}