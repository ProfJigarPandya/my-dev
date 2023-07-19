#include <stdio.h>
#include <conio.h>
void main()
{
 int count=10;
 int *ptr=&count;
 clrscr();
 while(*ptr)
 {
      (*ptr)--;
   printf("\n %d",count);

 }
 getch();

}