#include <stdio.h>
//Learning pointer to array applies to 2d array or more.
int main()
{
	/*
	int i;
	int array1d[10];
	int (*ptr)[10]=array1d;
	for(i=0;i<10;i++)
	{
		printf("%d\n",ptr[i]);
	}
	
 	ptrarra.c:7:24: warning: initialization of ‘int (*)[10]’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
    7 |         int (*ptr)[10]=array1d;
      |                        ^~~~~~~
ptrarra.c:10:26: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int *’ [-Wformat=]
   10 |                 printf("%d\n",ptr[i]);
      |                         ~^       ~
      |                          |       |
      |                          int     int *
      |                         %ls
*/

	
	
	int array2d[5][10];
	int i,j,k=0;
	int (*ptr)[10]=array2d;
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			array2d[i][j]=++k;
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			//printf("%d\t",array2d[i][j]);//Ex1
			//printf("%d\t",ptr[i][j]);//Ex2
			//printf("%d\t",*(*(ptr+i)+j));//Ex3
			printf("%d\t",*((*(ptr))+j)); //part1 of Ex4
		}
		printf("\n");
		ptr++; //part2 of Ex4
	}
	
	

}
