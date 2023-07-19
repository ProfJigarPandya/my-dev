#include <stdio.h>
#define R 20
#define C 8
int main()
{
	 int R1[R][C];
	 printf("Size of integer on this machine is %d\n",sizeof(int));
	 printf("Base address of array %p\n",R1);
	 printf("Address of element R1[15][5] is %p\n",&(R1[15][5]));
	 printf("Offset in terms of pointer to int element from base %d\n",(int *)&(R1[15][5])-(int *)R1);
	 printf("Hence, total bytes offset %d\n",((int *)&(R1[15][5])-(int *)R1)*sizeof(int) );
	 printf("Hence, if assumed the base address to be 1200 then address of R1[15][5] shall be %d\n",1200+((int *)&(R1[15][5])-(int *)R1)*sizeof(int) );
}
