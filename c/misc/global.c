
#include <stdio.h>
#include <conio.h>

int x=50;
void justfun();
void main()
{
int x=10;
clrscr();
printf("\n in main %d",x);


{
 int x=100;
 printf("\n %d",x);

}


justfun();

printf("\n in main %d",::x);

getch();

}
void justfun()
{
	x++;
}