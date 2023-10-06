/*
 pascal triangle using two 1d arrays reporesenting previous and current line.
 similar logic as of fibbo terms for lines than after.
*/

#include<stdio.h>
int main()
{
	int n;
	printf("Enter n. The number of terms final line. ");
	scanf("%d",&n);
	int i,j,k,prev[n],current[n];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			
			if(j==1 || j==i)
				current[j]=prev[j]=1;
			else
				current[j]=prev[j-1]+prev[j];
			printf("%d ",current[j]);
		}
		printf("\n");
		//copy current to prev
		for(k=2;k<=j;k++)
		{
			prev[k]=current[k];
		}
	}
	return 0;
}
