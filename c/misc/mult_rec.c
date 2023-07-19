/*
 mul(m,n) = m + mul(m,n-1);

 5*4 = 5 + ( 5 * 3 )

	   ( 5 * 3 ) =  5 + ( 5 * 2 )

			    ( 5 * 2 ) = 5 + ( 5 * 1 )

					    ( 5 * 1 )  = 5 + ( 5 * 0 )

							     (   0   )




 */


 int mul(int m,int n)
 {
   int result;

    if(n==0)
	return 0; // return m*n

    result = m + mul(m,n-1);
   return result;

 }




#include <stdio.h>
#include <conio.h>

void main()
{
 clrscr();


 printf(",\multiplication    %d", mul(5,4));


 getch();
}