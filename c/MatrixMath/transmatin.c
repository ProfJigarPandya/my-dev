/* program to transpose a matrix in-memory*/
#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 4
int main()
{
	int 
		m[ROW][COL]=
		{
//		 {1,2,3},
//		 {4,5,6},
//		 {7,8,9}
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}

		},
		temp,
		i,
		j;

	if(ROW!=COL)
	{
		printf("\n Number of rows must be same as number of columns. ");
		exit(1);
	}

	for(i=0;i<ROW;i++)
	{
		for(j=0;j<i;j++)
		{
			temp=m[i][j];
			m[i][j]=m[j][i];
			m[j][i]=temp;
		}
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%3d",m[i][j]);
		printf("\n");
	}
}
