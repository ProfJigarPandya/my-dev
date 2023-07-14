// will not work properly if last digit is 0 i.e 123450 -> 54321

#include <stdio.h>
#include <conio.h>

void main()
{
 long int no,on;
 clrscr();
 printf("\n Enter no. to be reversed ");
 scanf("%ld",&no);

 on=0;
 while(no!=0)
 {
	on = ( on * 10 ) + no % 10;
	no = no/10;
 }

 printf("reverse %ld",on);

 getch();
}