#include<stdio.h>
int main()
{
	int n;
	int row,col;
	//int flag;
	scanf("%d",&n);
	for(row=1;row<=n;row++)
	{
		//flag=1;
		if(row%3==0)
		{
			printf("%d",row);
		}
		else
		{

			for(col=1;col<=row;col++)
			{
				if(col%2)
				{
					printf("%d",col);
					//flag=0;
				}
				else
				{
					printf("*");
					//flag=1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
