/*
 * Read an integer 'num1' from user.
1)If the number if positive or zero:
Display number followed by count of total digits in it, if digit count is an ODD value. Otherwise Display the number only.
2)If number is negative:
Display number followed by count of total digits+1 in it, if digit count is an EVEN value. Otherwise Display the number only.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int num1;
	int totalDigits;
	scanf("%d",&num1);
	//special case
	if(num1==0)//Number count 1 is odd
	{
		printf("01");
		return 0;
	}
	if(num1>0)
	{
		totalDigits=0;
	}
	else
	{
		totalDigits=1;
	}

	printf("%d",num1);
	while(num1)
	{
		num1=num1/10;
		totalDigits++;
	}
	if((totalDigits%2))//As totalDigits is plus one already for negative number
	{
		printf("%d",totalDigits);
	}

    return 0;
}

