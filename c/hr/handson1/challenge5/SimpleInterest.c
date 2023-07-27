#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int principalAmount;
	float annualRateOfInterest;
	int durationOfLoan;

	scanf("%d",&principalAmount);
	scanf("%f",&annualRateOfInterest);
	scanf("%d",&durationOfLoan);

	float interestAmount;
	
	//Simple interest formula
	interestAmount = ((principalAmount * annualRateOfInterest)/100)*durationOfLoan;

	printf("%f",interestAmount);

    return 0;
}

