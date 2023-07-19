/*
for odd numbers starting 3
n=5

SSSSS
SSSSS
SSSSS
SSSSS
SSSSS


SSSSS
S   S
S   S
S   S
SSSSS


SSSSS
SSSSS
SSOSS
SSSSS
SSSSS


*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,row,column;
	printf("\n Enter n");	
	scanf("%d",&n);
	system("clear");

	if(!( (n>=3) && ( (n%2)==1 ) ))
	{
		printf("Try input n, any odd number starting 3 and onward");
		printf("%d",EXIT_FAILURE);
		exit(1);
	}
		
	
	for(row=1;row<=n;row++)
	{
		for(column=1;column<=n;column++)
		{
			printf("S");
		}
		printf("\n");
	}
	
	printf("\n\n");

	for(row=1;row<=n;row++)
	{
		for(column=1;column<=n;column++)
		{
			if(row==1 || column == 1 || row == n || column ==n)
				printf("S");
			else
				printf(" ");
		}
		printf("\n");
	}
	
	printf("\n\n");


	for(row=1;row<=n;row++)
	{
		for(column=1;column<=n;column++)
		{
			if( ((row == (n+1)/2) && (column==(n+1)/2)) )
				printf("O");
			else
				printf("S");
		}
		printf("\n");
	}
	
	printf("%d",EXIT_SUCCESS);
	return 0;	
}
