#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int * myFunction()
{
	//int arr[SIZE]={1,2,3};
	int i;
	int *d_arr=(int *) malloc(SIZE*sizeof(int));
	if(d_arr==NULL)
	{
		printf("\n Malloc failed ");
		exit(1);
	}
	for(i=0;i<SIZE;i++)
		d_arr[i]=i+1;
	return(d_arr);
}

int main()
{
	int i;
	int *p=myFunction();
	for(i=0;i<SIZE;i++)
	       printf("%d",*p++);
	return(0);	
}
