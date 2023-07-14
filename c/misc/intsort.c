/* sorting of integers */

#include <stdio.h>
#include <conio.h>
#define MAX 10

void main()
{
 int i,j,n,pass;
 int list[MAX];
 clrscr();

  printf("\n Enter numbers ");
  for(i=0;i<MAX;i++)
	scanf("%d",&list[i]);

  /* sorting starts */
  for(pass=1;pass<=MAX-1;pass++)
  {
	for(j=0; j<MAX-pass ;j++)
	{
	 if(list[j]>list[j+1])
	 {
		int temp;
		temp = list[j];
		list[j] = list[j+1];
		list[j+1] = temp;
	 }
	}
  }

  /* display sorted data */
  printf("\n");
  for(i=0;i<MAX;i++)
	printf(" %d",list[i]);



 getch();
}