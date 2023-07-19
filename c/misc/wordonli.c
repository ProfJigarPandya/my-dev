/* write a  program to display each word of an input on a separate line..*/
/*   indirectly need to remove mutliple blank */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
 char *str;
 char prevchar;
 clrscr();
 str = (char *) malloc(100);
 gets(str);
 prevchar = 'y';

 while(*str)
 {
  if(*str==' '){
	   prevchar=' ';
  }
  else if(prevchar==' ')
  {
	printf("\n");
	printf("%c",*str);
	prevchar=*str;
  }
  else
  {
      printf("%c",*str);
      prevchar=*str;
  }

  str++;

 }
 getch();
}