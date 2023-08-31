//Print 15 leap years from a given year
//1. If a year is divisible by 400 then its a leap year.
//2. Or if a year is divisible by 4 and NOT divisible by 100 then its a leap year.
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TIMES 15
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int inputYear;
	int t;
	scanf("%d",&inputYear);

	//Print 15 leap years
	t=0;
	while(1)
	{
		if( (!(inputYear%400)) || ( ((inputYear%100)) && (!(inputYear%4))))
		{
			t++;
			if(t==TIMES)
			{
				printf("%d",inputYear);//Note that during printing last entry no need to provide space afterward.
				break;
			}
			printf("%d ",inputYear);//intermediate with space
		}
		inputYear++;
	}
    return 0;
}

