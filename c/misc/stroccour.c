/*
 find occurance of a substring in original string and display the count.
*/
#include<stdio.h>
#include<string.h>

int stroccur(char [],char []);

int main()
{
	char str[20],sstr[20];
	int res;

	printf("Enter string1: ");
	gets(str);
	
	printf("Enter string2: ");
	scanf("%s",sstr);
	res= stroccur(str,sstr);
	printf("\n%s occured %d times in %s",sstr,res,str);
}

int stroccur(char srt[],char ssrt[])
{
	char *temp=NULL;
	int count =0;
		
	if(srt[0]=='\0' || ssrt[0]=='\0')
		return 0;
		
	do
	{
		temp=strstr(srt,ssrt);
		if(temp!='\0')
			count++;
		else
			break;
		
		srt=temp+strlen(ssrt);
	}while(1);

	return count;	
}	
