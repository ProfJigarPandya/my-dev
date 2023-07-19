/* program to transpose a matrix */
#include <stdio.h>
#define ROW 3
#define COL 3
int main()
{
	int 
		m1[ROW][COL]=
		{
		 {1,2,3},
		 {4,5,6},
		 {7,8,9}
		},
		m[ROW][COL],
		i,
		j;

	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			m[j][i]=m1[i][j];
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%3d",m[i][j]);
		printf("\n");
	}
}
