#include <stdio.h>

int isdigit(char r)
{
	if(r>='0'&&r<='9')
		return 1;
	else
		return 0;
}
void main()
{
   printf("%d",isdigit('9'));
}
