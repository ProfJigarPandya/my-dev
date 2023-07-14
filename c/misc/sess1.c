
/* write a program which takes a character input and display
   the character in opposite alphabatical case.
   Use getchar() and putchar()
*/

/* Assumption :  The input is a valid alphabatical character */


#include <stdio.h>
#include <conio.h>

void main()
{
 char ch;
 clrscr();

 ch = getchar();
 if( isupper(ch) )
	putchar(tolower(ch));
 else
	putchar(toupper(ch));

 getch();
}