/*
 Write a program to extract last N characters from the string and display it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int main()
{
	char str[MAX]={'\0'},output[MAX];
	int n,len,i,j;

	printf("\nEnter string");
	scanf("%s",str);
	printf("\nEnter n to extract last n characters from the input string");
	scanf("%d",&n);

	if(str==NULL || n<=0)
	{
		printf("\nCan't perform the operation. str is null or n is less or equal zero");
		return 1;
	}

	if(n>(MAX-1))//last position for null of the whole string
	{
		printf("\nCan't perform the operation. n > MAX-1 ");
		return 1; 
	}

	if(str[n]=='\0')
	{	if(str[n-1]!='\0')
			printf("\nExtracted string is the input itself. ");
		if(str[n-1]=='\0')
			printf("\nCan't perfom the operation because n greater than length");
	}
	else
	//skiping of length-n number of characters
	{
		i=0;
		while(str[i+n]!='\0')
		{
			i++;
		}
	
		len = i+n;

		//strcpy(output,&str[i]); //below loop logic can also be achieved via usage of string library function.
		for(j=0;j<n;j++)
		{
			output[j]=str[i++];
		}
		output[j]='\0';
		
		puts(output);
	}
	
 return 0;
}

