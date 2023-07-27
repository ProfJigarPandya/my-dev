#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int principalAmount;
	float annualRateOfInterest;
	const int durationOfLoan=3;

	scanf("%d",&principalAmount);
	scanf("%f",&annualRateOfInterest);

	float interestAmount;
	float compoundInterestAmount=0.0;
	
	//Compound interest step wise
	//Year 1
	interestAmount = ((principalAmount*annualRateOfInterest)/100);
	compoundInterestAmount+=interestAmount;

	//Year 2
	interestAmount = (((principalAmount+compoundInterestAmount) * annualRateOfInterest)/100);
	compoundInterestAmount+=interestAmount;

	//Year 3
	interestAmount = (((principalAmount+compoundInterestAmount) * annualRateOfInterest)/100);
	compoundInterestAmount+=interestAmount;

	//Note that above can be better way done using loop construct. 

	printf("%9.6f\n",compoundInterestAmount);

    return 0;
}

