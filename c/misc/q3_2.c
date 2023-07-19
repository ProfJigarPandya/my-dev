#include <stdio.h>

#define MAX 100

char *mystrcat(dest, src)
char  *dest;
const char *src;
{
	char *s1=dest;
	const char *s2=src;
	char c;
	do
	{
		c=*s1++;
	}while(c!='\0');

	s1-=2;
	do
	{
		c=*s2++;
		*++s1=c;
	}while(c!='\0');

	return dest;
}
int main()
{
	char s1[2*MAX+1]="Hello",s2[MAX]=" World";
	mystrcat(s1,s2);
	printf("%s",s1);
	
}
