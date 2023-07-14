#include <stdio.h>
#include <conio.h>

void factors(int n)
{
 static int flag=0;
 int i;
	if(flag==0)
	{
		printf("\t1");
		flag=1;
	}

	for(i=2;i<n;i++)
	{
		if(n%i == 0) //n is divided by i
		{
			printf("\t%d",i);
			factors(n/i);
			break;
		}

	}
	if(i==n)
		printf("\t%d",n);

}
void main()
{

 int n;
 clrscr();
 printf("\n Enter number to find factors of it ");
 scanf("%d",&n);
 factors(n);
 getch();
}