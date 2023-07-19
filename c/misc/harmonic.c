/* Harmonic series
	result = 1 + 1/2  + 1/3  + ............ + 1/n;

*/

#include <stdio.h>
#include <conio.h>

void main()
{
 int n,i;
 float result=1.0;
 clrscr();
 printf("\n Enter n for finding harmonic series      ");
 scanf("%d",&n );

 for(i=2;i<=n;i++)
 {
  result = result + ( 1.0 / i );
 }

 printf("\n Result = %f ",result);



 getch();
}