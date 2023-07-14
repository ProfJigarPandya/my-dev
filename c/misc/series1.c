 /*                           2     3               n
	1 / 1-x   = 1 + x +  x  + x   + .........+ x


	-1 < x <  1


	efficient one ...

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
   result=0; //the first term....is 1
   term=1;
   while(count<=n)
   {
	       /* find count th power of x  */
	 result = result + term;
	 term = term * x;
	 count++;
   }

   printf("\n final value of result is %f",result);






   getch();
}


/* sample output

 x = .75
 n= 34

 result = 3.999744 */