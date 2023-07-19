/*
	lower.c
	
	convert input to lower case.
*/
#include <stdio.h>
#include <ctype.h>

main()
{
	int c;
	
	while( (c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}	
