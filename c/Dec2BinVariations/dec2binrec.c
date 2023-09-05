#include <stdio.h>

void dec2bin(int dec)
{
	int remainder;
	int quotient;
	quotient=dec/2;
	remainder=dec%2;
	if(quotient)
		dec2bin(quotient);
	printf("%d",remainder);
}
int main()
{
	dec2bin(0);
	printf("\n");
	dec2bin(1);
	printf("\n");
	dec2bin(2);
	printf("\n");
	dec2bin(3);
	printf("\n");
	dec2bin(4);
	printf("\n");
	
	dec2bin(5);
	printf("\n");
	dec2bin(6);
	printf("\n");
	dec2bin(7);
	printf("\n");
}
