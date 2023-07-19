/* output

	*
	  *
	    *
	      *
		*

*/

#include <stdio.h>
#include <conio.h>

void main()
{
 int row,column;

 clrscr();

 row=1;

 while(row<=5)
 {
   column=1;
   while(column<row)  //2nd row than one space...
   {		      // like row's row than row-1 spaces
	printf(" ");
	column++;
   }

   printf("*\n");
   row++;

 }

 getch();
}