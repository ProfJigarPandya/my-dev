/* function with argument and
 NO return type

  printline()....

*/

#include <stdio.h>
#include <conio.h>

void printline(char ch,int no)
{
 int i;
 printf("\n");
 for(i=1;i<=no;i++)
  printf("%c",ch);
}

void main()
{
int i;
clrscr();
printline('+',80);
printf(" Number   Cube of Number");
printline('=',80);
for(i=1;i<10;i++)
{
printf("\n %4d %10d ",i,i*i*i);
}
printline('*',50);
printline('%',30);
getch();
}