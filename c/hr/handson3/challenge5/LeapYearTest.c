/*
 *Decide whether given year is a leap year or not.
An year would be leap year if it follows following conditions.
1. If a given year is divisible by 400 then it is always a leap year, no need to check any other condition. (e.g. 1600, 2000)
2. If a given year is not divisible by 400, but divisible by 100 then it is not a leap year. No need to check any other condition. (e.g.
1900, 2100)
3. If a given year is not divisible by 100 but divisible by 4, then it is leap year. (e.g. 1996, 2004, 2020)
4. If a given year is not divisible by 4 then it can not be a leap year. (e.g. 2019, 2021)
*/

#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int year;
	scanf("%d",&year);
	if(!(year%400))
	{
		printf("yes");
		return 0;
	}
	if(!(year%100))
	{
		printf("no");
		return 0;
	}
	if(!(year%4))
	{
		printf("yes");
		return 0;
	}
	printf("no");
	
    return 0;
}
