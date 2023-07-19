/*
 Write a program to extract last N characters from the string and display it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int main()
{
	char str[MAX],output[MAX];
	int n,len,startpos,i,j;

	printf("\nEnter string");
	scanf("%s",str);
	printf("\nEnter n to extract last n characters from the input string");
	scanf("%d",&n);

	//len=strlen(str);
	len=-1;
	while(str[++len]!='\0');
	
	printf("\n Length of the string %d",len);
	if( str==NULL || (str!=NULL && n>len) )
	{
		printf("\nCan't perform the operation.");
		return 1;
	}
	
	if(n==len)
	{
		printf("\nExtracted string is the input itself. ");
	}	
	else
	{
		startpos=len-n;
		printf("\n Resulting extracted string : \n");
		for(i=startpos,j=0;i<len;i++,j++)
		{
			output[j]=str[i];
			//printf("%c",str[i]);	
		}
		output[j]='\0';
		
		//strcpy(output,&str[startpos]); //above loop logic can also be achieved via usage of string library function.
		puts(output);
	}
	
 return 0;
}

