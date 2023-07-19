/*
       Write a program to detect the largest number out of 7 numbers and display it
    with using while loop.

*/
#include <stdio.h>
#define MAX 7
int main()
{
	int input,
	    largest,
	    counter=1;

	printf("Enter number for position %d ",counter);
	scanf("%d",&input);
	largest=input;
	counter++;
		
	while(counter<=MAX)
	{
		printf("Enter number for position %d ",counter);
		scanf("%d",&input);
		if(input>largest)
			largest=input;
		counter++;
	}
	
	printf("Largest number is %d ", largest);
	
}

