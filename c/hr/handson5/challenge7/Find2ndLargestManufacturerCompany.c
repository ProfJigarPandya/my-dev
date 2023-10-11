/*
 * Find out the 2nd Largset manufacturer Company from user data.
Input Format
Input will contain two lines - First line will have total number of companies i.e. n - Second line will have number of products
manufactured for company.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n;//Total number of companies
	scanf("%d",&n);
	int products[n];
	int i;
	int largestData,largestLocation;
	int largest2Data, largest2Location;
	scanf("%d",&products[0]);
	largestData=products[0];
	largestLocation=0;
	scanf("%d",&products[1]);
	largest2Data=products[1];
	largest2Location=1;
	int temp;
	if(largestData<largest2Data)
	{
		temp=largestData;
		largestData=largest2Data;
		largest2Data=temp;
		largestLocation=1;
		largest2Location=0;
	}

	for(i=3;i<n;i++)
	{
		scanf("%d",&products[i]);

		if(largest2Data>=products[i])//Both 1st and 2nd largest are still the same.
		{
			continue;
		}
		else
		{
			if(largestData>=products[i])//Only the 2nd changes
			{
				largest2Data=products[i];
				largest2Location=i;
			}
			else//newer largest
			{
				largest2Data=largestData;
				largest2Location=largestLocation;
				largestData=products[i];
				largestLocation=i;
			}
		}
	}
	printf("%d",largest2Location);



    return 0;
}

