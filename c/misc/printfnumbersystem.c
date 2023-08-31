#include <stdio.h>
#include <math.h>
int main()
{
	//unsigned int data=15;
	unsigned int data=32767;
	long int mask;
	int msb;
	int totalBytes=sizeof(unsigned int);
	printf("Decimal %d\n",data);
	printf("Hex %x\n",data);
	printf("Octal %o\n",data);
	printf("Binary ");
	for(msb=1;msb<=totalBytes*8;msb++)
	{
		mask=(unsigned int)pow(2.0,totalBytes*8-msb);
		printf("%d",(data&mask)>0?1:0);
	}
}
