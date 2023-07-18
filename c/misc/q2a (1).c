//Write a program that multiply two matrices M1[X][Y] and M2[Y][Z].

#include <stdio.h>
//#define X 1
//#define Y 3
//#define Z 4
#define X 2
#define Y 3
#define Z 4
int main()
{
	//int m1[X][Y]={{3,4,2}}, m2[Y][Z]={{13,9,7,15},{8,7,4,6},{6,4,0,3}};
	int m1[X][Y]={{1,-1,-4},{-3,2,3}}, m2[Y][Z]={{6,0,-1,1},{4,2,3,-3},{5,7,8,9}};
		
	int result[X][Z]={0,0,0,0};

	int i,j,k;
	//Assuming dimensions are as per rules.
	
	for(i=0;i<X;i++)
	{
		for(j=0;j<Z;j++)
		{
			for(k=0;k<Y;k++)
			{
				result[i][j]+=(m1[i][k]*m2[k][j]);
			}
		}
	}
	for(i=0;i<X;i++)
	{
		for(j=0;j<Z;j++)
		{
			printf("\t%d",result[i][j]);	
		}
		printf("\n");
	}
	return(0);
}
