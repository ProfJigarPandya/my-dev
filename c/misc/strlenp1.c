#include<stdio.h>
#include <string.h>
int f(char *p);
int main()
{
	char str[]={'\0'};
	printf("\n%d",f(str));
	printf("\n%d",strlen(str));
}
int f(char *p)
{
	char *q=p;
	while(*++p);
	return (p-q);
}
