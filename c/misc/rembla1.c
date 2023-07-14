/* replace sequence of blanks with a single blank */


#include <stdio.h>
#include <conio.h>

void main()
{
 char ch,lastc;
 lastc = 'a';
 clrscr();

 while((ch=getchar())!=EOF)
 {
   if(ch!=' ')
	putchar(ch);
   if(ch==' ')
	if(lastc!=' ')
		putchar(ch);

   lastc = ch;
 }

 getch();
}