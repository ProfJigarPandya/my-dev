#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int number = 5, *pntr;
	
	// storing address of variable number into integer pointer named pntr
	pntr = &number;

	printf("number = %d\n", number);
	// please note that this statement will print address of number
	printf("address of number = %p\n", (void *)&number);
	// this statement will print same address as printed in previous line
	printf("address stored in pntr = %p\n", (void *)pntr);
	// this statement will print value stored in variable pointed by pntr (number)
	printf("value at address pointed by pntr = %d\n", *pntr);

	number = 7;

	printf("\nAfter changing value of number to 7\n");
	printf("number = %d\n", number);
	// please note that changing value of number does not chage its address
	printf("address of number = %p\n", (void *)&number);
	// this statement will print same address as printed in previous line
	printf("address stored in pntr = %p\n", (void *)pntr);
	// this statement will print value stored in variable pointed by pntr (number)
	// This will print new value of number not the old
	printf("value at address pointed by pntr = %d\n", *pntr);

	return 0;
}
