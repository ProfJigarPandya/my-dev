#include <stdio.h>
#include <math.h>
#define BYTECONTAINSBITS 8
int main() {

    /* Enter your code here. */    
	int amountGivenP;//1 <= P <= 100,000,000
	float interestRatePerAnnumR;//5.5 <= R <= 60.5
	float loanInYearsN;//0.25 <= N <= 30

	//printf("%ld\n",sizeof(int));
	//printf("%F\n",pow(2.0,sizeof(int)*BYTECONTAINSBITS));//4,294,967,296
	
	scanf("%d",&amountGivenP);
	scanf("%f",&interestRatePerAnnumR);
	scanf("%f",&loanInYearsN);

	printf("%d",(int)(amountGivenP*interestRatePerAnnumR*loanInYearsN/100));//interest amount

	

    return 0;
}
