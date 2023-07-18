/*
 * In a small company there are ten salesmen. Each salesman is supposed to sell three
 * products. Write a program using a 2D array to print (i) the total sales by each salesman and
 * (ii) total sales of each product.
 */

#include <stdio.h>
#define TOT_SM 4
#define TOT_PRO 3
int main()
{
	int sales[TOT_SM][TOT_PRO], per_sm[TOT_SM]={0}, per_pro[TOT_PRO]={0};
	int sm,pro;
	printf("\nEnter data");
	for(sm=0;sm<TOT_SM;sm++)
	{
		printf("\nEnter for salesman# %d ",sm+1);
		for(pro=0;pro<TOT_PRO;pro++)
		{
			printf("\nProduct#%d",pro+1);
			scanf("%d",&sales[sm][pro]);
		}
	}
	
	//Sum up per sales man
	for(sm=0;sm<TOT_SM;sm++)
	{
		for(pro=0;pro<TOT_PRO;pro++)
		{
			per_sm[sm]+=sales[sm][pro];
		}
	}
	
	//Sum up per product
	for(pro=0;pro<TOT_PRO;pro++)
	{
		for(sm=0;sm<TOT_SM;sm++)
		{
			per_pro[pro]+=sales[sm][pro];
		}
	}

	printf("\nThe total sales by each salesman");
	printf("\n%10s%15s","SalesMan#","Total Sales");
	for(sm=0;sm<TOT_SM;sm++)
	{
		printf("\n%10d%15d",sm+1,per_sm[sm]);			
	}

	printf("\nThe total sales of each product");
	printf("\n%10s%15s","Product#","Total Sales");
	for(pro=0;pro<TOT_PRO;pro++)
	{
		printf("\n%10d%15d",pro+1,per_pro[pro]);			
	}

	return(0);
}
