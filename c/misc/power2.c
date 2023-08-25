#include <stdio.h>
#include <math.h>
int main()
{
	int power;
	for(power=0;power<20;power++)
	{
		printf("%4d %8f\n",power,pow(2.0,power));
	}
	return 0;
}
