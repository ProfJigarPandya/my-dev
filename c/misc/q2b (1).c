/*
 * Write a program using function which contains two arguments source string and sub-string.
 * The function will return the total number of occurrences of a substring in a source string
 */
#include <stdio.h>

#define MAXSOURCE 500
#define MAXSUB 50

int findOccurrences(char source[],char sub[]);
int main()
{
	char source[MAXSOURCE]="Write a program using function which contains two arguments source string and sub-string. The function will return the total number of occurrences of a substring in a source string. The function helps top-down modular approach. function has multiple categories. Learn string as well.";
	//char sub[MAXSUB]="function";	
	//char sub[MAXSUB]="unknown";	
	//char sub[MAXSUB]="source";	
	//char sub[MAXSUB]="function";	
	//char sub[MAXSUB]="string";	
	char sub[MAXSUB]="The";	
	int count;

	count=findOccurrences(source,sub);
	printf("\nSource is \"\"\"%s\"\"\"",source);
	printf("\nSub is \"\"\"%s\"\"\"",sub);
	printf("\n Substring occurs %d times in source string",count);
	return(0);
}
int findOccurrences(char source[],char sub[])
{
	int count=0;
	int src=0,subc=0;
	while(source[src])
	{
		subc=0;
		while(sub[subc]==source[src])
		{
			subc++;
			src++;
		}
		if(sub[subc]=='\0')
		{
			count++;
		}
		src++;
	}
	return count;
}
