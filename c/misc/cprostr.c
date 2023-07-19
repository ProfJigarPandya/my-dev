/* String formation using "*.*s",width,charno,str
   C
   CP
   CPR
   CPRO
   .....
   .
   .
   CPROGRAMMING
   ------------
   CPROGRAMMING
   CPROGRAMMIN
   CPR.....
   .
   .
   .
   C


*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
char str[]="CProgramming";
int i;
clrscr();

for(i=1;i<=12;i++)
{
       printf("\n|%*.*s|",-12,i,str);
       //printf("\n|%*.1s|",i,str);
       //printf("\n|%.*s|",i,str);
}

printf("\n|------------|");

for(i=12;i>=1;i--)
{
	printf("\n|%*.*s|",-12,i,str);
}

getch();
}