//For given marks decide grade of students based on following rules.
//marks >= 90 AA grade
//marks >= 80 and marks < 90 AB grade
//marks >= 70 and marks < 80 BB grade
//marks >= 60 and marks < 70 BC grade
//marks >= 50 and marks < 60 CC grade
//marks >= 40 and marks < 50 CD grade
//marks < 40 DD grade

#include <stdio.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int marks;
	scanf("%d",&marks);
	//Just because marks are all in multiple of 10s swith use is simpler. Else range has to be implemented using if only
	switch(marks/10)
	{
		case 9:
			printf("AA");
			break;
		case 8:
			printf("AB");
			break;
		case 7:
			printf("BB");
			break;
		case 6:
			printf("BC");
			break;
		case 5:
			printf("CC");
			break;
		case 4:
			printf("CD");
			break;
		default:
			printf("DD");
			break;
	}
    return 0;
}
