/* Find mean, median and mode of list of ﬂoating point numbers, correct up to two decimal places.
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 99999

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	float inputArray[MAX];
	float unumbers[MAX]={0},ucounts[MAX]={0},ulen=0;
	unsigned int n=0;
	float temp;
	int i, j;
	double sum=0;
	do
	{
		scanf("%f",&temp);
		if(temp==-1)
		{
			break;
		}
		inputArray[n++]=temp;	
		sum=sum+temp;
	}while(1);
	
	//mean
	
	//printf("\n Mean is ");
	printf("%.2f ",sum/n);

	//median
	//The Median is the middlemost element of a given data set. Point at which half the data is more and half the data is less. 
	//Inplace sorting
	for(i=1;i<n;i++)
	{
		temp=inputArray[i];
		j=i-1;
		while( (j>=0) && (inputArray[j]>temp)){
			inputArray[j+1]=inputArray[j];
			j--;
		}
		inputArray[j+1]=temp;
	}
	/*printf("Sorted array\n");
	for(i=0;i<n;i++)
		printf("%.2f ",inputArray[i]);
	
	printf("\nn is %d\n",n);*/

	if(n%2)//odd
	{
		//printf("\nOdd numbers\n");
		//printf("\n Median is ");
		printf("%.2f ",inputArray[n/2]);//middle element. i.e. 9/2=>4=> (0,1,2,3) 4 (5,6,7,8)
	}
	else
	{
		//printf("\nEven numbers\n");
		//printf("\n Median is ");
		printf("%.2f ",((inputArray[(n/2)-1]+inputArray[(n/2)])/2.0)); //8/2=>4=> (0,1,2) (3,4) (5,6,7)
	}
	
	//mode: The most frequent number—that is, the number that occurs the highest number of times.
	//Find frequency
	unumbers[0]=inputArray[0];
	ucounts[0]=1;
	ulen=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<ulen;j++)
		{
			if(inputArray[i]==unumbers[j])
			{
				ucounts[j]++;
				break;
			}
		}
		if(j==ulen)//not present already in the unique list
		{
			unumbers[j]=inputArray[i];
			ucounts[j]=1;
			ulen++;
		}
	}
	
	//find max
	float maxoccr=ucounts[0];
	int maxoccrlocation=0;
	int maxoccrtimes=1;
	for(j=1;j<ulen;j++)
	{
		if(maxoccr==ucounts[j])//more than one mode
		{
			maxoccrtimes++;
		}
		else if(maxoccr<ucounts[j])
		{
			maxoccr=ucounts[j];
			maxoccrlocation=j;
			maxoccrtimes=1;
		}
		//else continue; //ignore the data having less occurances.
	}
	
	if(n==1)
	{
		//printf("\n Only single record case ");
		//printf("\n Mode is ");
		printf("-1.00");
	}
	else if(ulen==1)
	{	
		//printf("\nAll records are same case");
		//printf("\n Mode is ");
		printf("-1.00");
	}
	else if(maxoccrtimes==1)
	{
		//printf("\n Unique mode found");
		//printf("\n Mode is ");
		printf("%.2f",unumbers[maxoccrlocation]);
	}	
	else
	{
		//printf("\n Otherwise case.");
		//printf("\n Mode is ");
		printf("-1.00");
	}

    return 0;
}

