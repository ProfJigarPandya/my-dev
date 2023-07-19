#include <stdio.h>
#include <conio.h>

void main()
{
int n,temp,result,j;
clrscr();
//printf("\n Enter no. ");
//scanf("%d",&n);

for(n=2;n<500;n++)
{
	temp=n;
	result=0;

	while(temp!=0)
	{
		j=temp%10;
		result = result + j * j * j;
		temp =temp/10;
	}
	if(result == n)
		printf("\t %d ",n);

}
getch();
}