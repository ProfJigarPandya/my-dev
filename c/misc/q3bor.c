/*
Develop a program to apply sorting to given names of scientists.
- Initialize scientists names into data_set. 
- Read the sort_order (ascending/descending) as input from user 
- Generate result_set according to chosen order. data_set must not be changed. 
- Display result_set finally.
*/

#include <stdio.h>
#include <string.h>

#define TOTAL_SCI 5
int main()
{
	char data_set[TOTAL_SCI][100]={"Charles Babbage","Tim Berners-Lee","Sanjeev Arora","Dennis Ritchie","Alan Turing"};
	char result_set[TOTAL_SCI][100], temp[100];
	int sort_order, i, pass, cmp;
	printf("\n Enter sort order 1-ascending ,2-descending");
	scanf("%d",&sort_order);
	
	//copy over
	for(i=0;i<TOTAL_SCI;i++)
	{
		strcpy(result_set[i],data_set[i]);
	}

	for(pass=0;pass<(TOTAL_SCI-1);pass++)
	{
		for(cmp=0;cmp<(TOTAL_SCI-1-pass);cmp++)
		{
			
			if( ( (sort_order == 1) && (strcmp(result_set[cmp],result_set[cmp+1])>0)) || ((sort_order == 2) && (strcmp(result_set[cmp],result_set[cmp+1])<0)) )
			{
				strcpy(temp,result_set[cmp]);
				strcpy(result_set[cmp],result_set[cmp+1]);
				strcpy(result_set[cmp+1], temp);			
			}
		}	
		
	}

	
	for(i=0;i<TOTAL_SCI;i++)
	{
		printf("\n%s",result_set[i]);
	}
}
