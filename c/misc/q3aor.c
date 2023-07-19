#include <stdio.h>


/*Develop a program to process experimental exp_matrix for 3 experiments conducted 7 days of given dry run week. exp_matrix – represents readings recorded. Operation populateFindings, populates minimum and maximum reading of each day for further processing into range_matrix, very much like populating range of exp_matrix day wise as findings.  Display range_matrix upon request.
*/

//Note that findings expected day wise not experiment wise.

#define TOT_EXPR 3
#define DAYSOFW 7
#define RANGE_LR 2
void populateFindigs(int exp_matrix[][DAYSOFW], int range_matrix[][RANGE_LR]);
int main()
{
	int exp_matrix[TOT_EXPR][DAYSOFW]={{3,21,4,6,7,4,3},{12,34,2,4,21,45,6},{34,2,334,5,3,4,5}};
	int i,j, d,e;
	int range_matrix[DAYSOFW][RANGE_LR];
	
	//take input
	/*printf("\n Enter data");
	for(i=0;i<TOT_EXPR;i++)
	{
		for(j=0;j<DAYSOFW;j++)
		{
			printf("\n(Exp#%d,Days#%d)",i+1,j+1);
			scanf("%d",&exp_matrix[i][j]);
		}
	}*/
	
	populateFindigs(exp_matrix, range_matrix);
	
	for(d=0;d<DAYSOFW;d++)
	{
		printf("\n Day# %d (%d-%d)",d,range_matrix[d][0],range_matrix[d][1]);
	}

}

void populateFindigs(int exp_matrix[][DAYSOFW], int range_matrix[][RANGE_LR])
{
	int d, e, min, max;

	for(d=0;d<DAYSOFW;d++)
	{
		min=max=exp_matrix[0][d];
		for(e=1;e<TOT_EXPR;e++)
		{
			if(exp_matrix[e][d]<min)
			{
				min=exp_matrix[e][d];
			}	
			else if (exp_matrix[e][d]>max)
			{
				max=exp_matrix[e][d];
			}
		}
		range_matrix[d][0]=min;
		range_matrix[d][1]=max;
	}
}
