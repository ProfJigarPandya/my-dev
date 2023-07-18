/* Write a structure named as country which should have members like country name, population of a country and literacy level. Write a program which will sort and display the information of ten countries in descending order of population.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNTRIES 10

struct country
{
	char name[50];
	int population;
	float literacy_level;
};

void getdata(int max_countries, struct country countries[]);
void sort(int max_countries,struct country countries[]);
void display(int max_countries, struct country countries[]);
int main()
{
	struct country countries[MAX_COUNTRIES];
	getdata(MAX_COUNTRIES,countries);
	printf("\nOriginal List of countries");
	display(MAX_COUNTRIES,countries);
	sort(MAX_COUNTRIES,countries);
	printf("\nList of countries sorted by population descending order");
	display(MAX_COUNTRIES,countries);
}
void getdata(int max_countries, struct country countries[])
{
	int i;
	for(i=0;i<max_countries;i++)
	{
		printf("\n Enter Name: ");
		scanf("%s",countries[i].name);
		printf("\n Enter Population: ");
		scanf("%d",&countries[i].population);
		printf("\n Enter Literacy Level :");
		scanf("%f",&countries[i].literacy_level);
	}
}
void sort(int max_countries,struct country countries[])
{
	int pass;
	int loc;
	struct country tempcoun;

	if(max_countries<=0)
		exit(1);

	for(pass=1;pass<max_countries;pass++)
	{
		for(loc=0;loc<(max_countries-1-(pass-1));loc++)
		{
			if(countries[loc].population<countries[loc+1].population)
			{
				tempcoun = countries[loc];
				countries[loc] = countries[loc+1];
				countries[loc+1] = tempcoun;
			}		
		}
	}
}
void display(int max_countries, struct country countries[])
{
	int i;
	printf("\n %50s %20s %20s","Name","Population","Literacy Level");
	for(i=0;i<max_countries;i++)
	{
		printf("\n %50s",countries[i].name);
		printf("%20d ",countries[i].population);
		printf("%20f ", countries[i].literacy_level);
	}
}
