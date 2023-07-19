/*
Q2(A) Write a program to swap the biggest and smallest number in the array of 10 elements using function. Create three functions “FindBig()” ,“FindSmall()” and “swap()”. “FindBig()” and “FindSmall()” these functions are used to find big and small elements, and “swap()” will work for swapping those numbers. Pass array as an argument to all functions.

See here we are returning position and using them. Instead of this we can also return actual data and let swap locate and swap.
*/

#include<stdio.h>
int FindBig(int[10]);
int FindSmall(int[10]);
void swap(int,int,int[10]);

main()
{
	int i,arr[10],maxpos,minpos;
	printf("Enter 10 elements:\n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	maxpos=FindBig(arr);
	minpos=FindSmall(arr);
	printf("After swapping,numbers are:\n");	
	swap(maxpos,minpos,arr);
	for(i=0;i<10;i++)
		printf("%d\n",arr[i]);
}

int FindBig(int arr[])
{
	int max=arr[0],maxpos=0,i;
	for(i=1;i<10;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			maxpos=i;
		}
	}
	return maxpos;
}

int FindSmall(int arr[])
{
	int min=arr[0],minpos=0,i;
	for(i=1;i<10;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
			minpos=i;
		}
	}
	return minpos;
}

void swap(int maxpos,int minpos,int arr[])
{
	int temp;
	temp=arr[maxpos];
	arr[maxpos]=arr[minpos];
	arr[minpos]=temp;
}
