#include <stdio.h>
#include <conio.h>

void main()
{
 char string[100],prevchar;
 int i,len;
 clrscr();
 printf("\n enter string ");
 gets(string);

 len = strlen(string);
 prevchar ='y';

 for(i=0;i<len;i++)
 {
  if(prevchar!=' ')
	prevchar=string[i];
  else if(string[i]!=' ')
  {
      if(islower(string[i]))
	string[i] = toupper(string[i]);
      prevchar = string[i];
  }
  else
	continue;
 }

 printf("%s",string);



 getch();
}