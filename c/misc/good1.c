/* if user enters any no. then
 i,e 12345 then display
	  12345
	  2345
	  345
	  45
	  5

	  */

#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 long int no,temp,i=0;

 clrscr();
 printf("\n Enter any no.");
 scanf("%ld",&no);
 temp=no;
 while(temp/=10)  i++;
 printf("%ld",no);
 while(i)  printf("\n%ld",no%(long int)pow(10,i--));
 getch();
}