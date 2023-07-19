/*
Q1(D) Write the logic to print the Pascal triangle.
*/

#include<stdio.h>
main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int i,j,p[n][n];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(j==1 || j==i)
				p[i][j]=1;
			else
				p[i][j]=p[i-1][j-1]+p[i-1][j];
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
