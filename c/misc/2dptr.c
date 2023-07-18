//Array of pointers for 2 dimensional int array
#include<stdio.h>
#include<stdlib.h>

void prnt(int **x,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\n [%d] [%d] x=%d",i,j,*(*(x+i)+j));
		}
	}
}
void rddata(int **x,int r,int c)
{
	int i,j,*y;
	for(i=0;i<r;i++)
	{
		y=(int *) malloc(c * sizeof(int));
		*(x+i)=y;
		for(j=0;j<c;j++)
		{
			scanf("%d",y+j);
		}
		
	}

}

void freeall(int **x, int r, int c)
{
 
	int i,j;
	for(i=0;i<r;i++)
	{
		free(*(x+i));
	}
	free(x);
}
int main()
{
	int i,n,**x,*y,r,c,j;
	printf("Enter total numbers of row and column");
	scanf("%d %d",&r,&c);

	x=(int **) malloc(r * sizeof(int *));

	rddata(x,r,c);
	prnt(x,r,c);	
	freeall(x,r,c);
	
	return 0;
}

