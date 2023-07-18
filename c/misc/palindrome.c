/*
Q2(C)(i)Write a program to check whether the string is palindrome or not.Write appropriate message.
*/

#include<stdio.h>
#include<string.h>
main()
{
	int i,len;
	char str[50],rev[50];
	printf("Enter string: ");
	scanf("%s",str);
	len=strlen(str);

	for(i=0;i<len;i++)
	{
		rev[i]=str[len-1-i];    //Reverse string//
	}
	rev[len]='\0';
	
	if(strcmp(str,rev)==0)
		printf("The string is a palindrome\n");
	else
		printf("The string is not a palindrome\n");
}

