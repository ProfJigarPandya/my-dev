#include <stdio.h>
#include <conio.h>

void main()
{

 int count=0;
 int n=2,i;

 clrscr();

 do
 {

   for(i=2;i<=n-1;i++)
   {
      if(n%i == 0)
	break;
   }

   if(i==n)
   {
	printf("  %d",n);
	count++;
   }
   if(count==100)
	break;
   n++;
 }while(1);

 getch();
}