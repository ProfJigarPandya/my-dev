/*
 *Write a program that will read two strings from the user and copy the first n characters of
string 2 at the end of string 1. Display appropriate output.
 */

#include <stdio.h>
#include <string.h>
#define MAX 100
int main()
{
	char input1[2*MAX],input2[MAX];
	int n,l1,l2,i ;
	printf("\nEnter string1");
	scanf("%s",input1);
	printf("\nEnter string2");
	scanf("%s",input2);
	printf("\nEnter n");
	scanf("%d",&n);
	l1=strlen(input1);
	l2=strlen(input2);
	
	for(i=0;i<n && i<l2;i++)
	{
		input1[l1+i]=input2[i];
	}
	input1[l1+i]='\0';
	printf("\nAfter processing the input1 string is ");
	puts(input1);	
	
}
