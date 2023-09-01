#include <stdio.h>
#include <math.h>
enum boolean {false,true};
int main()
{
	unsigned int data=15;
	long int mask;
	int msb,bit;
	enum boolean flagShowZeroes;
	int totalBytes=sizeof(unsigned int);
	printf("Decimal %d\n",data);
	printf("Hex %X\n",data);
	printf("Hex %x\n",data);
	printf("Octal %o\n",data);
	printf("Binary ");
	if(data==0)
		printf("0");
	else
	{
		flagShowZeroes=false;//do not show preceding zeroes
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
}
