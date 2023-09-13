/* a no. is a perfect no. if
	sum of all its factor is equal to the original no.

	Actually, sum of all proper factors i.e. 28 => 1, 2, 4, 7, 14 => 28
	i.e. 6 => 1, 2, 3 => 6
	496
	8128
etc.

Logic here needs to be improved for efficiency. May be with use of prime number.

	i.e.  1+2+3 = 6; so, 6 is a perfect no. */


#include <stdio.h>
//#include <conio.h>

int main()
{
 long int no,i,sum,nintermed;

 //no=6;
 //no=28;
 //no=496;
 //no=8128;
 


 //clrscr();
 for(no=3;no<250000;no++)
 {

  sum=1;
  nintermed = no;
  i=2;
  while(i<nintermed)
  {
	//printf("%ld %ld\n",i,nintermed);

	if(nintermed%i==0)
	{
		sum+=i;
		//printf(" sum is %ld \n",sum);
		//nintermed=nintermed/i;
		//i=2;
	}
	i++;
  }

  if(sum==no)
  {
	printf("\nYes %ld",no);
  }
  else
  {
	//printf("\nNo %ld",no);
  }

 }


 //getch();
 return 0;
}
