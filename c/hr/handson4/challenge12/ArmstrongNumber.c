//Write a program to check whether given number is armstrong or not.print 1 if number is armstrong, 0 otherwise. 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int givenNumber,n; 
	int result;
	int mod;
	int div;

	scanf("%d",&givenNumber);
	n=givenNumber;
	
	//Find out the total number of digits to be used as power to digit's base
	int length=0;
	while(1)
	{
		n=n/10;
		length++;
		if(n==0)
		{
			break;
		}
	}

        result=0;
	int digit;
	n=givenNumber;
	while(n>0)
        {
                digit=n%10;
                result = result + pow(digit,length);
                n =n/10;
        }
        if(result == givenNumber)
                printf("1");
	else
		printf("0");

    return 0;
}

