/* Manage sales by number of persons and products.*/
#include <stdio.h>
#define PERSONS 3
#define PRODUCTS 5
int main()
{
	int sales[PERSONS][PRODUCTS]={0},salesByPerson[PERSONS]={0},salesByProduct[PRODUCTS]={0};
	int i,j,k,count=1,sum;
	int totalQuantities=0, quantitiesByPersons=0,quantitiesByProducts=0;
	for(i=0;i<PERSONS;i++)
	{
		for(j=0;j<PRODUCTS;j++)
		{
			sales[i][j]=count++;
			//scanf("%d",&sales[i][j]);
		}
	}
	for(i=0;i<PERSONS;i++)
	{
		for(j=0;j<PRODUCTS;j++)
		{
			totalQuantities+=sales[i][j];
		}
	}
	for(i=0;i<PERSONS;i++)
	{
		sum=0;
		for(j=0;j<PRODUCTS;j++)
		{
			sum+=sales[i][j];
		}
		salesByPerson[i]=sum;
	}
	for(k=0;k<PERSONS;k++)
	{
		quantitiesByPersons+=salesByPerson[k];
	}
	for(i=0;i<PRODUCTS;i++)
	{
		sum=0;
		for(j=0;j<PERSONS;j++)
		{
			sum+=sales[j][i];
		}
		salesByProduct[i]=sum;
	}
	for(k=0;k<PRODUCTS;k++)
	{
		quantitiesByProducts+=salesByProduct[k];
	}

	printf("\n Total Quantities %d",totalQuantities);
	printf("\n Quantities by Persons %d",quantitiesByPersons);
	printf("\n Quantities by products %d",quantitiesByProducts);


}
