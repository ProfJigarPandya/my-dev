/* summation  of numbers entered by user......
	 input 0 will indicate user want to stop entry ... and
		want to view result
		USING ::: GOTO
		*/

#include <stdio.h>
#include <conio.h>
void main()
{
	int number,sum=0;
	clrscr();

INPUT:	printf("\n enter any no.. 0 will stop entry and display sum ");
	scanf("%d",&number);

	if(number != 0)
	{
		sum = sum + number;
		goto INPUT;
	}
	else
	{
		printf("\n the result %d ",sum);
	}
	getch();



}


/* also display the total numbers entered by the user ??? */

