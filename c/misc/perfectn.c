/* a no. is a perfect no. if
	sum of all its factor is equal to the original no.

	i.e.  1+2+3 = 6; so, 6 is a perfect no. */


#include <stdio.h>
#include <conio.h>

void main()
{
 long int no,i,sum,temp;
 clrscr();
 for(no=3;no<1000;no++)
 {

  sum=1;
  temp = no;
  i=2;
  while(temp!=1)
  {
	if(temp%i==0)
	{
		sum+=i;
		temp=temp/i;
		i=2;
	}
	else
	   i++;
  }

  if(sum==no)
  {
	printf("\n %d ",no);
  }

 }


 getch();
}