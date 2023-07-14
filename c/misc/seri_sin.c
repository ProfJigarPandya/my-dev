/* use functions to  evaluate following series

		       3         5            7
		     x         x            x
   f(x) =   x  -   -----   + ------  -    ----- + ..................
		     3!        5!           7!

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

double power(int m,int n)
{
	double result=1.0;
	while(n--)
	{
		result*=m;
	}
	return  result;
}
long double factorial(int no)
{
 long double result=1;
 int i;

 for(i=1;i<=no;i++)
	result*=i;
 return result;
}

void main()
{
 double result;
 int x=15,term=35,i,po,sign;

 clrscr();

 result = x;
 po=3;
 i=2;
 sign = -1;
 while(i<=term)
 {

  result = result +  ( (sign) *  ( ( power(x,po) / factorial(po)) ) );

  po+=2;
  sign = (-1) * sign;
  i++;
 }

 printf("The result of the series %lf ",result);

 getch();


 printf("\n original %lf",sin(15));

 getch();
}
