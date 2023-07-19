/*
Develop a program to process budget allocation for 5 kids about 12 months for each. 
-budget_matrix - represents budget allocation. 
-extra_money_matrix [5 X 1] represents extra money value to be applied to current budget, very much like which kid shall be given how much extra money to spend every month. This extra money will be different for different kids. 
-Operation rowAdder is to add appropriate extra money in row elements of budget_matrix, provided in corresponding row of extra_money_matrix. Moreover, rowAdder operation resets all elements of extra_money_matrix to 1 after applying addition. 
-Display budget_matrix upon request.

*/
#include <stdio.h>
#define TOT_KIDS 5
#define YEAR_MONTHS 12
void displayBudget(int budget_matrix[][YEAR_MONTHS]);
void displayExtra(int extra_money_matrix[]);
void rowAdder(int budget_matrix[][YEAR_MONTHS],int extra_money_matrix[]);
int main()
{
	int budget_matrix[TOT_KIDS][YEAR_MONTHS]={{3,4,4,3,2,7,5,5,3,2,4,6},{4,3,4,5,2,4,2,4,5,6,6,6},{2,3,4,5,2,4,3,4,5,6,6,3},{4,3,4,5,2,5,6,7,7,2,3,4},{2,3,4,5,5,6,3,3,4,6,7,9}};
	int extra_money_matrix[TOT_KIDS]={2,4,5,3,1};
	printf("\n Original budget matrix");
	displayBudget(budget_matrix);
	displayExtra(extra_money_matrix);
	rowAdder(budget_matrix,extra_money_matrix);
	displayBudget(budget_matrix);
	displayExtra(extra_money_matrix);
	return(0);
}

void displayBudget(int budget_matrix[][YEAR_MONTHS])
{
	int i,j;
	for(i=0;i<TOT_KIDS;i++)
	{
		printf("\n");
		for(j=0;j<YEAR_MONTHS;j++)
		{
			printf("\t%d",budget_matrix[i][j]);
		}
	}
}

void rowAdder(int budget_matrix[][YEAR_MONTHS],int extra_money_matrix[])
{
	
	int i,j;
	for(i=0;i<TOT_KIDS;i++)
	{
		printf("\n");
		for(j=0;j<YEAR_MONTHS;j++)
		{
			budget_matrix[i][j]+=extra_money_matrix[i];
		}
		extra_money_matrix[i]=1;
	}
}

void displayExtra(int extra_money_matrix[])
{
	int i;
	for(i=0;i<TOT_KIDS;i++)
	{
		
		printf("\n%d",extra_money_matrix[i]);
	}
}
