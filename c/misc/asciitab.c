#include <stdio.h>
#include <conio.h>

void main()
{
 int i;
 clrscr();

 for(i=0;i<128;i++)
 {    if(i%4 == 0)
	    printf("\n");
	 printf("|   %3d   %c   |",i,i);
 }


 getch();

}









