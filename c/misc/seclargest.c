/*
Write a program to read an array of 10 floating point numbers. Display the position [4]
of the second largest number.
*/

#include <stdio.h>

#define MAX 10
int main()
{
 int arr[MAX]
	//={1,2,3,4,5,6,7,8,9,10};
	//={10,9,8,7,6,5,4,3,2,1};
	//={9,8,7,6,5,4,3,2,1,10};
	//={1,2,2,2,2,2,2,2,2,2};
	={2,2,2,2,2,2,2,2,2,2};

 int i;
 int currmax, prevmax;

 /* printf("\nEnter input numbers");
 for(i=0;i<MAX;i++)
 {
	scanf("%d",&arr[i]);
 }
*/
 if(arr[0]>arr[1])
 {
 	 prevmax=1;
	 currmax=0;
 }
 else
{
 	 prevmax=0;
	 currmax=1;
}
 for(i=2;i<MAX;i++)
 {
	if(arr[i]>arr[currmax])
	{
		prevmax=currmax;
		currmax=i;
	}
 }

 printf("\n Second largest position is %d  and value is %d ",prevmax, arr[prevmax]);
 printf("\n Largest position is %d  and value is %d ",currmax, arr[currmax]);
}
