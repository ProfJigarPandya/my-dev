/*Write a program to read n floating point numbers in an array. Also, update the array to
 * insert a new number at the specified location.*/
#include <stdio.h>

#define MAX 100
int main()
{
	int data[MAX], n, i , loc;
	
	printf("\n Enter n");
	scanf("%d",&n);

	printf("\nEnter array data ");
	for(i=0;i<n;i++)
		scanf("%d",&data[i]);
	
	printf("\n Enter location. From 1 to %d",n);
	scanf("%d",&loc);
		
	
	
	for(i=n;i>(loc-1);i--)
		data[i]=data[i-1];	

	printf("\n Enter new element");
	scanf("%d",&data[i]);
	
	n++;


	printf("\n After insertion");
	for(i=0;i<n;i++)
	{
		printf("\n%d",data[i]);

	}
	
}
