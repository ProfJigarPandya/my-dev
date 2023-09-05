#include <stdio.h>
#define MAX 100
int main()
{
	//int dec=0;
	//int dec=1;
	//int dec=2;
	//int dec=3;
	//int dec=4;
	//int dec=5;
	//int dec=6;
	int dec=7;
	int array[MAX];
	int quotient, remainder;
	int i=0;
	do
	{
		remainder=dec%2;
		dec=dec/2;
		array[i++]=remainder;		
	}while(dec);
	for(int j=i-1;j>=0;j--)
		printf("%d",array[j]);
}
