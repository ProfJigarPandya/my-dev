#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	int           r;
	unsigned int  seed, nloops;
	while(1)
	{
               seed = arc4random();
               srand(seed);
               r =  rand()%99;
	       if(isdigit(r)||isalpha(r)||isspace(r))
	               printf("%c", r);
	}
}
