//Convert given number to binary, octal and hexadecimal
//Without using printf %x or %o, write a program to convert given decimal number to binary, octal and hexadecimal. Please DO NOT even use array, or function recursion to solve this.
//Output Format
//First line should contain binary representation of given number.
//Second line should contain octal representation of given number.
//Third line should contain hexadecimal representation of given number.
#include <stdio.h>
#include <math.h>
enum hexvalue {Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,A,B,C,D,E,F};
void printfHexValue(enum hexvalue hv);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int givenNumber;
	scanf("%d",&givenNumber);

	int remainder;
	int numberSystemBase;
	int gn;
	long int result;
	int length;
	
	//For decimal to binary
	numberSystemBase=2;
	gn=givenNumber;
	length=0;
	remainder=result=gn%numberSystemBase;
	do
	{
		gn=gn/numberSystemBase;
		remainder=gn%numberSystemBase;
		length++;

                if(remainder==1)
                {
                         result = remainder * pow(10,(length)) + result; //To take care of preceding zeroes
                }

	}while(gn);
	printf("%ld\n",result);	

	//For decimal to octal
	numberSystemBase=8;
	gn=givenNumber;
	length=0;
	remainder=result=gn%numberSystemBase;
	do
	{
		gn=gn/numberSystemBase;
		remainder=gn%numberSystemBase;
		length++;
		
                if(remainder>=1)
                {
                         result = remainder*pow(10,(length)) + result ; //To take care of preceding zeroes
                }

	}while(gn);
	printf("%ld\n",result);	



	//For decimal to hexa	
	numberSystemBase=16;
	gn=givenNumber;
	length=0;
	remainder=result=gn%numberSystemBase;
	printf("Hexa needs to be read reverse from whatever is displayed. Look for next version of this file for another approach.");
	do
	{

		printfHexValue((enum hexvalue)remainder);
		printf("\n");
		gn=gn/numberSystemBase;
		remainder=gn%numberSystemBase;
		length++;
		
                if(remainder>=1)
                {
                         result = remainder * pow(10,(length)) + result; //To take care of preceding zeroes
                }

	}while(gn);
	//printf("%ld",result);	
		
    return 0;
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


/* Sample input/output
 *
 * (960)10 = (3C0)16
 *  (49)10 = (31)16
 *  (1228)10 = (4CC)16
 *  (600)10 = (258)16
 */
