#include <stdio.h>
#include <math.h>
enum boolean {false,true};
int main()
{
	unsigned int data=5024;
	long int mask;
	int msb,bit;
	enum boolean flagShowZeroes=false;//do not show zeroes
	int totalBytes=sizeof(unsigned int);
	printf("Decimal %d\n",data);
	printf("Hex %x\n",data);
	printf("Octal %o\n",data);
	printf("Binary ");
	for(msb=1;msb<=totalBytes*8;msb++)
	{
		mask=(unsigned int)pow(2.0,totalBytes*8-msb);
		bit=data&mask;
		if(bit)
		{
			printf("1");
			flagShowZeroes=true;
		}
		else if(flagShowZeroes)
			printf("0");
	}
}
