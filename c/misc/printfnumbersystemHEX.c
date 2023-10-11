#include <stdio.h>
#include <math.h>
enum boolean {false,true};
enum hexvalue {Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,A,B,C,D,E,F};
void printfHexValue(enum hexvalue hv);
int main()
{
	unsigned int data=15;
	long int mask;
	int msb,bit;
	enum boolean flagShowZeroes;
	int totalBytes=sizeof(unsigned int);
	long int decimalSummation=0;
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
				//printf("1");
				decimalSummation+=(long int)pow(16.0,totalBytes*8-msb);
				flagShowZeroes=true;
			}
			else if(flagShowZeroes)
			{
				printf("0");
			}
		}
		
		

		//printfHexValue((enum hexvalue)remainder);
	}
}
void printfHexValue(enum hexvalue hv)
{
	switch(hv)
	{
		case 0:
			printf("0");
			break;
		case 1:
			printf("1");
			break;
		case 2:
			printf("2");
			break;
		case 3:
			printf("3");
			break;
		case 4:
			printf("4");
			break;
		case 5:
			printf("5");
			break;
		case 6:
			printf("6");
			break;
		case 7:
			printf("7");
			break;
		case 8:
			printf("8");
			break;
		case 9:
			printf("9");
			break;
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;
		case 12:
			printf("C");
			break;
		case 13:
			printf("D");
			break;
		case 14:
			printf("E");
			break;
		case 15:
			printf("F");
			break;
		default:
			printf("N/A");
	};
}

