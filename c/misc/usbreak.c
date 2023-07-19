#include <stdio.h>
#include <conio.h>

void main()
{

 int m;
 float x,sum,average;

 clrscr();

 sum=0;
 for(m=1;m<=100;m++)
 {

	scanf("%f",&x);

	if(x<0)
		break;

	sum= sum+x; // sum+=x;

 }



 average = sum / (float) (m-1);

 printf("\n No. of values %d ",m-1);

 printf("\n sum %f ",sum);
 printf("\n Average %f",average);



 getch();
}