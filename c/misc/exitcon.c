/* Exit controlled loop using goto */

#include <stdio.h>
#include <conio.h>
void main()
{
int count=1;

clrscr();

Start:

		printf("\n*"); //statements to repeat

		count++;

		if(count<=10)
		{

			goto Start;
		}

getch();
}