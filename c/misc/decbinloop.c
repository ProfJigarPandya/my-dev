/*
Write program to read an integer. If it is positive then display corresponding [6]
binary representation of that number. The user must enter 999 to stop. In the case
the user enters a negative number then ignore that input and ask the user to re-
enter any different number.
*/
#include <stdio.h>
#include <math.h>
int main()
{
	int number;
	int mod;
	int count;
	int result;
	do
	{
		printf("\nEnter input number" );
		scanf("%d",&number);
		
		if(number<0)
			continue;

		if(number==999)
			break;
	
		result = 0;
		count = 0;
		while(number)
		{
			mod=number%2;		
		
			if(mod==1)
			{
				result = pow(10,count) + result;	
			}
			number/=2;	
			count++;
		}
		printf("\nResult binary is %d ",result);

	}while(1);

}
