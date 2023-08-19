//Read an integer 'num1' from user.
//1)If the number if positive or zero: Display number followed by count of total digits in it
//2)Otherwise: Display the number followed by total digits + 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int num1;
	int totalDigits;
	scanf("%d",&num1);


	//special case.
	if(num1==0)
	{
		printf("01");//0 as number itself and has single digit
		return 0;
	}

	if(num1>0)//Number is positive or zero
	{
		totalDigits=0;
	}
	else
	{
		totalDigits=1;
	}

	//Commonly lets find out total digits accordingly. Note that they totalDigits initialized according to condition check requirment.
	printf("%d",num1);//Let's display the number itself anyways. This avoids use of temp variable.
	while(num1)
	{
		totalDigits++;
		num1=num1/10;
	}

	printf("%d",totalDigits);
	
    return 0;
}

