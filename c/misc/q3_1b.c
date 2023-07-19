#include <stdio.h>
char *myFunc(char *ptr)
{
	ptr+=2;
	return (ptr);
}
int main()
{
	char *x="HELLO", *y;
	y = myFunc(x);
	printf("%c\n",*y);
	printf("%s\n",y);
	return 0;	
}
