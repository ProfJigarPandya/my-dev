/* Entry controlled loop using goto */

#include <stdio.h>
#include <conio.h>
void main()
{
int count=1;

clrscr();

Start:
	if(count<=10)
	{

		printf("\n*"); //statements to repeat

		count++;
		goto Start;
	}

EXIT:

getch();
}