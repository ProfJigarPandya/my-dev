#include <stdio.h>
#include <conio.h>

void main()
{
 char choice;
 clrscr();

 printf("\n Would u like to know my name?");
 choice = getchar();

 if(choice=='y'||choice=='Y')
	printf("\nMy name is james ");
 else
	printf("\n You are good for nothing ");



 getch();

}