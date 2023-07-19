/* multiplication table */

#include <stdio.h>
#include <conio.h>

void main()
{
 int n;
 int row,column;

 clrscr();
 printf("\n enter rows for muliplication table ");
 scanf("%d",&n);

 row=1;
 while(row<=n)  //print n rows
 {
       column = 1;
       while(column<=10)	// print all elements of a row
       {
	 printf(" %d\t",row*column);
	 column++;
       }
       printf("\n");
       row++;
 }

 getch();
}