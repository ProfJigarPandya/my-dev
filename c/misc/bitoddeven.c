//Aim: Find out whether input number is odd or even using bitwise operations
//Logic: With bitwise operators 1 & 0 is 0 while 1 & 1 is 1. 
//	 The right most bit of odd number will be always one in binary representation.
//	 The right most bit of even number will be always zero in binary representation.
//	 Masking any number with 1 (decimal) whose binary is all zero with rightmost being 1, results in decimal 1 or 0 and this can help us decide whether number is odd or even.
//	 Decimal number 0 is even for following reason

//Zero is an even number.  An integer n is called *even* if there exists  an integer m such that n = 2m, and *odd* if n+1 is even.  From this, it is clear that 0 = (2)(0) is even.  The reason for this definition is so that we have the property that every integer is either even or odd.

#include <stdio.h>
#include <stdlib.h>
#define MASK 1
int main()
{
	int number, nmask;
	system("clear");
	printf("Enter a number");
	scanf("%d",&number);
	nmask = number & MASK;
	printf("\nNumber after mask is %d ",nmask);
	(nmask == 1) ? printf("\nInput number is an odd number ") : printf ("\nInput number is an even number ");
	return 0;
}
