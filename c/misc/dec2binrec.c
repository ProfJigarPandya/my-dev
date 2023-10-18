#include <stdio.h>
void dec2bin(int n);
int main()
{
	for(int dec=0;dec<=100;dec++)
	{
		printf("%d => ",dec);
		dec2bin(dec);
		printf("\n");
	}
}
void dec2bin(int n)
{
	int remainder=n%2;
	
	if(n/2)
	{
		dec2bin(n/2);
	}
	printf("%d",remainder);
}
