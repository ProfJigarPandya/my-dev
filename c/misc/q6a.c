/*
Write a program to persist data to file named “data2016_17.txt” about satellite movement over regions. Line of data contains region name, longitude, latitude and temperature separated by comma. Either insert a movement line or show total number of movements until now as per choice. Know that the program runs only during day time everyday.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char region_name[50];
	int longitude, latitude, temperature;
	
	FILE *fp;
	
	char ch;

	int choice, count=0;
	
	fp = fopen("data2016_17.txt","a+");
	if(fp == NULL)
	{
		printf("\n File opening error");
		exit(1);
	}

	if(ftell(fp)==0)
		fprintf(fp, "%s,%s,%s,%s","region_name", "longitude", "latitude", "temperature");
	
	while(1)
	{
		printf("\n Enter choice. 1. Enter movement. 2. Show total movements. 3. Exit. ");
		scanf("%d",&choice);
	
		getchar();

		switch(choice)
		{
			case 1://Enter movement
				printf("\n Enter regionname");
				scanf("%s",region_name);
				printf("\n Enter longitude, latitude, temperature");
				scanf("%d %d %d",&longitude, &latitude, &temperature);
				fprintf(fp, "\n%s,%d,%d,%d",region_name, longitude, latitude, temperature);
				break;
			case 2:
				count=0;
				
				if(ftell(fp)!=0)
					fseek(fp,0,0);
				do
				{
					if((ch = getc(fp))==EOF)
						break;
					
					if(ch == '\n')
						count++;
											
				}while(1);
				printf("\n Total %d movements are recorded till now ", count);
				break;
			case 3:
			default:
				printf("\n Good Bye !");
				exit(0);
		}
	}
	fclose(fp);
		
}
