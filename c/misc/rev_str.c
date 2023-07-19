#include <stdio.h>
#include <conio.h>


void reverse()
{
  char ch;

  ch = getchar();

  if(ch!=EOF)
	reverse();

 printf("%c",ch);



}

void main()
{
clrscr();
reverse();
getch();
}