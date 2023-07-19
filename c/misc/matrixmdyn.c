/*
Using dynamic memory allocation technique, develop a program for m X n matrix addition, where m and n is entered by user. */
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int m,n, i,j;
	int *pm1, *pm2, *pres;
	
	printf("\n Enter m");
	scanf("%d",&m);
	printf("\n Enter n");
	scanf("%d",&n);


	pm1 = (int *) malloc(sizeof(int)*m*n);
	pm2 = (int *) malloc(sizeof(int)*m*n);
	pres = (int *) malloc(sizeof(int)*m*n);

	if(pm1==NULL || pm2==NULL || pres==NULL)
	{
		printf("\n malloc failure ");
		exit(1);
	}

	printf("\n Enter matrix1 data");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf ("\n Enter element [%d][%d]",i+1,j+1);
 			scanf("%d",pm1++);
		}
	}
	
	printf("\n Enter matrix2 data");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf ("\n Enter element [%d][%d]",i+1,j+1);
 			scanf("%d",pm2++);
		}
	}
	
	pm1=pm1-(m*n);
	pm2=pm2-(m*n);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*pres=*pm1+++*pm2++;
			printf ("%d",*pres++);
		}
		printf("\n");
	}
	
	return(0);	
}

