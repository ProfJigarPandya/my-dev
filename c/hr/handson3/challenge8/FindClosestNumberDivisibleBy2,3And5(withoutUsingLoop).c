//Find closest number divisible by 2, 3 and 5 (without using loop)
//For a given number ﬁnd the closest number divisible by 2, 3 and 5. Closest number could be smaller or greater than a given number. If there are two numbers which are divisible by 2, 3 and 5 and are at same distance from a given number, then output smaller number.
#include <stdio.h>
#define TRIO 2*3*5
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int givenNumber;
	scanf("%d",&givenNumber);

	int leftNumber, rightNumber;
	leftNumber = givenNumber/(TRIO) * (TRIO);
	rightNumber= leftNumber + (TRIO);
	//printf("%d %d %d",leftNumber, givenNumber, rightNumber);
	int leftDistance, rightDistance;
	leftDistance = givenNumber-leftNumber;
	rightDistance = rightNumber-givenNumber;
	if(leftDistance==rightDistance)
	{
		printf("%d",leftNumber);//print smaller
	}
	else if(leftDistance<rightDistance)
	{
		printf("%d",leftNumber);//left is nearer
	}
	else
	{
		printf("%d",rightNumber);//right is nearer
	}


	
    return 0;
}
