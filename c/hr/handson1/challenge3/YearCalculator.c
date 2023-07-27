#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MONTHS_IN_A_YEAR 12
#define DAYS_IN_A_MONTH 30
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int totalDays;
	scanf("%d",&totalDays);

	int years, months, days;

	years=totalDays/(MONTHS_IN_A_YEAR*DAYS_IN_A_MONTH);
	totalDays=totalDays%(MONTHS_IN_A_YEAR*DAYS_IN_A_MONTH);

	months=totalDays/DAYS_IN_A_MONTH;
	totalDays=totalDays%DAYS_IN_A_MONTH;

	days=totalDays;

	printf("%d:%d:%d",years,months,days);


	
    return 0;
}

