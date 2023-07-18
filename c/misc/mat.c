/*
OR-Q3 (B)Write a program to find XA+YB where A & B are two 3X3 Matrices.Here the value of X and Y will be taken from user.
*/

#include<stdio.h>
void getdata(int[3][3]);
void display(int[3][3]);
main()
{
	int i,j,A[3][3],B[3][3],net[3][3],X,Y;
	printf("Enter elements of matrix1:\n");
	getdata(A);
	printf("Enter elements of matrix2:\n");
	getdata(B);
	printf("Matrix1 i.e. A is:\n");
	display(A);
	printf("Matrix2 i.e. B is:\n");
	display(B);
	
	printf("Enter X:\n");
	scanf("%d",&X);
	printf("Enter Y:\n");
	scanf("%d",&Y);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			net[i][j]=(X*A[i][j]+Y*B[i][j]);	
		}
	}
	printf("XA + YB is :\n");
	display(net);
}
void getdata(int m[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter %d%d position element:  ",i,j);
			scanf("%d",&m[i][j]);
		}
	}
}
void display(int m[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}
