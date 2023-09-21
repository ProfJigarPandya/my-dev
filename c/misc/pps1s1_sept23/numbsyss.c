#include <stdio.h>
int main()
{
	int data1=31,data2=056,data3=0X89;
	printf("Display1: Data %o\n",data1);//decimal to octal display supported by printf itself
	printf("Display2: Data %X\n",data1);//decimal to Capital Hexa display supported by printf itself
	printf("Display3: Data %d\n",data2);//Octal value 56 is stored as binary into memory of data2 101110 is equal decimal 46
	printf("Display4: Data %d",data3);//Hexa value 89 is stored as binary into memory of data3 10001001 is equal decimal 137
	return 0;
}
