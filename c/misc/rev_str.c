#include <stdio.h>


void reverse()
{
  char ch;

  ch = getchar();

  //In LINUX press Ctrl+d to indicate end of input
  if(ch==EOF)
	  return;

 reverse();

 printf("%c",ch);



}

void main()
{
reverse();
}
