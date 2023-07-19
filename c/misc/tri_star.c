/*

9
8 7
6 5 4
3 2 1 0

*/

#include <stdio.h>
#include <conio.h>



void main()
{
  int i,j,count;
  clrscr();

  count=9;
  for(i=1;i<=4;i++)
  {
	for(j=1;j<=i;j++)
	{
	   printf("%d ",count--);
	}
	printf("\n");
  }


  getch();
}
