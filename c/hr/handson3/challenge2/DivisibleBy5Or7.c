//Read a number from user and print it, if it is divisible by either 5 or 7, print 0 otherwise.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int input;
	scanf("%d",&input);
	if((!(input%5)) || (!(input%7)))//Note that C language considers 0 as false and non-zero as true.
		printf("%d",input);
	else
		printf("0");
    return 0;
}

