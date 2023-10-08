/*
Find GCD of two posititve numbers using The Euclidean Algorithm.
Recall that the Greatest Common Divisor (GCD) of two numbers m and n is the largest number that divides both m and n.
The Euclidean Algorithm is a technique for quickly finding the GCD of two integers.
Define function named find_gcd which takes two numbers and returns a number. Use euclidean algorithm to implement find_gcd
function. Call find_gcd function from main with input numbers as arguments and print number returned by find_gcd function.
The Euclidean Algorithm for finding GCD(A,B) is as follows:
If A = 0 then GCD(A,B)=B, since the GCD(0,B)=B, and we can stop.
If B = 0 then GCD(A,B)=A, since the GCD(A,0)=A, and we can stop.
Write A in quotient remainder form (A = B⋅Q + R)
Find GCD(B,R) using the Euclidean Algorithm since GCD(A,B) = GCD(B,R)
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	unsigned long int num1, num2, temp;
	scanf("%lu",&num1);
	scanf("%lu",&num2);
	unsigned long int resultGCD=-1;
	unsigned long int quotient, remainder, count;
	
	count=1;
	while(1)
	{
		//printf("\nNum1 %lu with Num2 %lu round %lu",num1,num2,count);
		if(num1==0)
		{
			resultGCD=num2;
			break;
		}
		else if (num2==0)
		{
			resultGCD=num1;
			break;
		}
		else
		{
			//quotient=num1/num2;
			/*if(num1<num2)
			{
				temp=num1;
				num1=num2;
				num2=temp;
			}*/
			remainder=num1%num2;
			num1=num2;
			num2=remainder;
			//printf("%lu\n",remainder);
		}
		count++;
	}	
	printf("%lu",resultGCD);

    return 0;
}

