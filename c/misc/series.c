 /*                           2     3               n
	1 / 1-x   = 1 + x +  x  + x   + .........+ x


	-1 < x <  1

 */

#include <stdio.h>
#include <conio.h>

void main()
{
   int n,count,i;
   float x;
   float result;
   float term;

   clrscr();


   printf("\n enter x");
   scanf("%f",&x);

   printf("\n enter n");
   scanf("%d",&n);

   count=1;
   result=1; //the first term....is 1
   while(count<=n)
   {
	       /* find count th power of x  */
	       i=1;
	       term=1;
	       while(i<=count)
	       {
		   term = term * x;
		   i++;
	       }

	 result = result + term;
	 count++;
   }

   printf("\n final value of result is %f",result);






   getch();
}