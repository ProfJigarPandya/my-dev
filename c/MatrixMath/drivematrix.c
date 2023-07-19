/* 
Driver program for using my matrix library 
drivematrix.c
*/

#include <stdio.h>
#include "matrix.h"
#define R 3
#define C 3
int main()
{
	int i,j,
		m1[R][C]={{1,2,3},{4,5,6},{7,8,9}},
		m2[R][C]={{11,12,13},{14,15,16},{17,18,19}},
		m[R][C],
		status
	;
	/*printf("Please, enter two %dx%d matrices ",R,C);
	for(i=0;i<R;i++)
	{
	 	for(j=0;j<C;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	for(i=0;i<R;i++)
	{
	 	for(j=0;j<C;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}*/
	
	status=addmatrices(m1,R,C,m2,R,C,m);

	if(status==0)
	{
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				printf("%5d",m[i][j]);
			}
			printf("\n");
		}
	}	
	else
		printf("Two matrices of different size can not be added.");

	return 0;
}
