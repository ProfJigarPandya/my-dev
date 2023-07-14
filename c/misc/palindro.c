#include <stdio.h>
#include <conio.h>

void main()
{
long int n,temp,result=0;
clrscr();
printf("\n Enter no. ");
scanf("%ld",&n);
temp=n;
while(temp!=0)
{
	result = result * 10 + temp%10;
	temp = temp/10;
}
if(result==n)
	printf(" \n The no. is palindrome ");
else
	printf("\n The no. is not palindrome");





getch();
}