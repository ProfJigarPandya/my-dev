/*(1) Write a structure named as hotel which should have members like hotel name, hotel star rating and tariff per day. Write a user defined function which will find and display the information of a hotel having highest tariff per day from ten hotels.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_HOTELS 10
struct hotel
{
	char name[50];
	int star_rating;
	float tariff_per_day;
};

void getdata(int max_hotels, struct hotel hotels[]);
int findHighTariff(int max_hotels,struct hotel hotels[]);
void display(struct hotel h);
int main()
{
	struct hotel hotels[MAX_HOTELS];
	int highTariffHotelIndex=-1;
	getdata(MAX_HOTELS,hotels);
	highTariffHotelIndex = findHighTariff(MAX_HOTELS,hotels);
	printf("\nHotel having highest tariff");
	display(hotels[highTariffHotelIndex]);
}
void getdata(int max_hotels, struct hotel hotels[])
{
	int i;
	for(i=0;i<max_hotels;i++)
	{
		printf("\n Enter Name: ");
		scanf("%s",hotels[i].name);
		printf("\n Enter Star Rating [1..5]: ");
		scanf("%d",&hotels[i].star_rating);
		printf("\n Enter Tariff Per Day :");
		scanf("%f",&hotels[i].tariff_per_day);
	}
}
int findHighTariff(int max_hotels,struct hotel hotels[])
{
	int i;

	if(max_hotels<=0)
		exit(1);

	int highTariffHotelIndex=0;
	int highestTariff=hotels[0].tariff_per_day;

	for(i=1;i<max_hotels;i++)
	{
		if(hotels[i].tariff_per_day>highestTariff)
		{
			highTariffHotelIndex = i;
			highestTariff=hotels[i].tariff_per_day;
		}		
	}
	return highTariffHotelIndex;
}
void display(struct hotel h)
{
	printf("\n Name: %s",h.name);
	printf("\n Star Rating [1..5]: %d ",h.star_rating);
	printf("\n Tariff Per Day : %f ", h.tariff_per_day);
}
