//Decimal to binary of a positive number without array and recursion
//It supports input 1 to 1023
//Jigar M. Pandya
//21/01/2014
// compile using: gcc dec2binwo.c -lm -std=c99
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	long int
		number,
		n,
		mod,
		result=1,
		length=0 // length is represents length of actual result, number of digits including preceding zeroes
	;

	system("clear");
	printf("Enter number ");
	scanf("%d",&number);	
	
     //for(int i=1;i<=30;i++)
     {
	
	printf(" number, mod, result, length \n");
	//n=number=i;
	n=number;
	if(number>=1 && number < 1024)
	{
		result = mod = number % 2;
		length=1;
		do
		{
			printf("%5d %5d %5d %5d\n",number, mod, result, length);
			number/=2;
			
			length++;
			mod = number % 2;
			
			if(mod==1)
			{
				result = pow(10,(length-1)) + result; //To take care of preceding zeroes of actual result
			}
		}
		while(number);
		printf(" Dec %ld to binary %ld \n\n",n, result);
	}
	else
		printf(" Only positive integers are supported. [1-1023] ");
	
      }

printf("Have a nice day!!\n");

}
