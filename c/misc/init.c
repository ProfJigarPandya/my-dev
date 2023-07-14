#include <stdio.h>
#include <conio.h>

void main()
{
 int arr[5]={1,2,3},i;
 char str[]="hello";
 clrscr();
 for(i=0;i<5;i++)
	printf("\n %d ",arr[i]);

 printf("%s",str);
 getch();
}