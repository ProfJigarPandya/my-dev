/*      change case of input character....
	i.e.      if uppercase then display lower.. and viceversa...
*/


#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;
	clrscr();
	printf("\t");
	ch = getchar();

     if(isalpha(ch))
     {
	if(islower(ch)) 		//putchar(toupper(ch))
	{
		ch=toupper(ch);
		printf("\t%c",ch);
	}
	else
	{
		ch=tolower(ch);
		printf("\t%c",ch);
	}
     }
     else
     {
	printf("\n non-alpha ");
     }


	getch();
}