//For a given month and year, output number of days in that month.
#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int month, year;
	int isLeapYear=0;
	scanf("%d %d",&month,&year);
	
	if((!(year%400))||((year%100)&&(!(year%4))))
	{
		isLeapYear=1;//True
	}
	switch(month){
		case 2:
			if(isLeapYear)
			       printf("29");
			else
				printf("28");
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31");
			break;
		default:
			printf("30");
	}

    return 0;
}
