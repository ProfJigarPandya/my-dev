#include <stdio.h>
#include <conio.h>

 void main()
 {
  char *name="Delhi";
  char *cptr=name;
  int length;
  clrscr();
  while(*cptr != NULL)
  {
    printf("%c is stored at address %u  \n",*cptr,cptr);
    cptr++;
  }
  length = cptr - name;
  printf("\n Length of the string %d ",length);



  getch();
 }


