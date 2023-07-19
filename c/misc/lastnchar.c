/*
Q2 (B)(i)Write a program to extract last N characters from the string and display it.
*/

#include<stdio.h>
#include<string.h>
main()
{
	int i,pos,n;
	char str[50];
	printf("Enter string: ");
	scanf("%s",str);
	printf("Enter n: ");
	scanf("%d",&n);
	pos=strlen(str)-n;
	printf("\nlast n characters of the string are: ");
	for(i=pos;i<strlen(str);i++)
		printf("%c",str[i]);
	printf("\n");
	return 0;
}
	
	
