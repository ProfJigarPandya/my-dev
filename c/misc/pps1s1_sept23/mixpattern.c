#include<stdio.h>
int main()
{
	int n;
	int row,col,flag;
	scanf("%d",&n);
	for(row=1;row<=n;row++)
	{
		flag=1;
		for(col=1;col<=row;col++)
		{
			if(row%3==0)
			{
				printf("%d",row);
				break;
			}
			else
			{
				if(flag)
				{
					printf("%d",col);
					flag=0;
				}
				else
				{
					printf("*");
					flag=1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
