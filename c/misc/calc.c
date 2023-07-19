#include <stdio.h>
#include <conio.h>

void main()
{
 char ch;
 int n1,n2;
 clrscr();


 printf("\n enter the operand; ");
 scanf("%c",&ch);

 printf("\n enter the operand; ");
 scanf("%d",&n1);

 printf("\n enter the operand; ");
 scanf("%d",&n2);

 if(ch=='+')
	printf("%d",n1+n2);
 else  if(ch=='-')
	printf("%d",n1-n2);
 else  if(ch=='*')
	printf("%d",n1*n2);
 else  if(ch=='/')
	printf("%d",n1/n2);
 else
	printf("Sorry");



 getch();
}
