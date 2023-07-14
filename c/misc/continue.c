/* use of continue ..............*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 int count,negative;
 double number,sqroot;
 clrscr();

 printf("\n enter 9999 to stop \n");
 count = 0;
 negative =0;
 while(count<=100)
 {
	printf("\n enter a no");
	scanf("%lf",&number);

	if(number == 9999)
		break;
	if(number<0)
	{
		printf("\n no. is negative ");
		negative++;
		continue;	//skip rest of the loop statement....
	}

	sqroot = sqrt(number);
	printf(" \n Number  = %lf , square root %lf  ",number,sqroot);
	count++;
  }

  printf("\nNumber of items done %d ",count);
  printf("\n Negative numbers  %d ",negative);




 getch();
}