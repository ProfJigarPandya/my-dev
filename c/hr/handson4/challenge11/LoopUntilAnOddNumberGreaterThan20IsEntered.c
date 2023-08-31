//Loop until an odd number greater than 20 is entered
//Write a C program which reads integer from user, stopping when an  odd number greater than 20 is entered.The total number of even and odd numbers entered should then be displayed to the screen.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int givenNumber;
	int countOdds=0, countEvens=0;
    do
    {
	scanf("%d",&givenNumber);
	if(givenNumber%2)
		countOdds++;
	else
		countEvens++;
	if(((givenNumber>20) && (givenNumber%2)))
		break;

    }while(1);
    printf("Even:%d Odd:%d",countEvens,countOdds);
    return 0;
}

