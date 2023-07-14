/* function without argument and return type

  printline()....

*/

#include <stdio.h>
#include <conio.h>

void printline()
{
 int i;
 printf("\n");
 for(i=1;i<=80;i++)
  printf("=");
}

void main()
{
int i;
clrscr();
printline();
printf(" Number   Cube of Number");
printline();
for(i=1;i<10;i++)
{
printf("\n %4d %10d ",i,i*i*i);
}
printline();

getch();
}