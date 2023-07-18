/*
 * Write a program that will interchange the biggest and the smallest number from list of
 * integers and display the modified list.
 */
#include <stdio.h>
int main()
{
	//int data[]={1,2,3,4,5,6,7};
	//int data[]={6,5,4,3,2,1};
	//int data[]={1,1,2,2,3};
	//int data[]={1,5,2,5,7,4,3,9,2,4};
	//int data[]={1};
	//int data[]={1,2};
	int data[]={2,1};
	//int data[]={1,3,2};
	int n=sizeof(data)/sizeof(int);
	int i;int temp;
	int min, max, minindex, maxindex;
	minindex=maxindex=0;
	min=max=data[minindex];

        printf("\nActual Dataset\n%10s","Location: ");
        for(i=0;i<n;i++)
        {
                printf("\t%d",i+1);
        }
	printf("\n%10s","Data: ");
        for(i=0;i<n;i++)
        {
                printf("\t%d",data[i]);
        }

	for(i=1;i<n;i++)
	{
		if(data[i]<min)
		{
			min=data[i];
			minindex=i;	
		}
		else if(data[i]>max)
		{
			max=data[i];
			maxindex=i;
		}
	}
	
	temp=data[minindex];
	data[minindex]=data[maxindex];
	data[maxindex]=temp;

	printf("\nAfter swapping max (location %d) and min (location %d) \n%10s",maxindex+1,minindex+1,"Location: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",i+1);
	}
	printf("\n%10s","Data: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",data[i]);
	}
	printf("\n");
	return(0);
}
