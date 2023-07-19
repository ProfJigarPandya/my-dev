/*
Using dynamic memory allocation functions to manage voting. Here for the village, admin shall enter the known population and based on it the first memory list be created in the program. Voter enters candidate number whom he/she wants to vote, store it in created memory. Grow the memory by 100 count more and continue voting whenever it reaches memory limit.

*/
#include <stdio.h>
#include <stdlib.h>

#define INCFACTOR 100
int main()
{
	int *votes;
	int known_population;	int current_population;
	int count=0, i, choice;

	printf("\nEnter known population:");
	scanf("%d",&known_population);
	getchar();
	current_population = known_population;
	votes=(int *) malloc(known_population*sizeof(int));
	if(votes==NULL)
	{
		printf("\n malloc failed during votes memory allocation");
		exit(1);
	}

	while(1)
	{
		printf("\n Enter 1. Vote. 2. See all. 3. Exit. ");
		scanf("%d",&choice);
		getchar();
		if(choice==1)
		{
			printf("\n Enter your vote");
			if(count==current_population)
			{
				current_population+=INCFACTOR;				
				votes=(int *) realloc(votes,current_population);
				if(votes==NULL)
				{
					printf("\n Re-alloc failed. Data loss risk. ");
					exit(1);
				}
				printf("\nMemory has been expanded to accomodate %d votes",current_population);
			}
			scanf("%d",&votes[count++]);
		}
		else if(choice==2)
		{

			if(count==0)
			{
				printf("\nNo votes available yet");
				continue;
			}
			for(i=0;i<count;i++)
				printf("\n%d",votes[i]);
		}
		else
			exit(0);
	}

	free(votes);
}
