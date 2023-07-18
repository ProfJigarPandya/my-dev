/*
  Write a program to perform sum and multiplication of all digits of entered
number and print the entered number in the reversed order.
*/
#include <stdio.h>
int main()
{
	int number,
		mod,
		sum=0,
		multiplication=1;

	printf("Enter input number");
	scanf("%d",&number);

	printf("Reverse number is ");
	while(number>0)
	{
		mod = number % 10;
		printf("%d",mod);
		sum+=mod;
		multiplication*=mod;
		number/=10;
	}
	printf("\n Summation of all digits is %d", sum);
	printf("\n Multiplication of all digits is %d",multiplication);
}
