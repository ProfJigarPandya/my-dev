#include <stdio.h>
int main()
{
	int n;
	int iterations=0;
	n=48;
	//n=3;
	//n=13;
	//n=24;
	while(n>1)
	{
		if(n%2 == 0)
		{
			n=n/2;
		}
		else
		{
			//n=3*n+1;
			n=3*n+3; //e.g. n=48, the loop never stops. As it repeats over and over with n=12 value 
		}
		iterations++;
		printf("\n %d. Press any key to iterate further...",n);
		getchar();
	}
	printf("You have a nice day!");
	printf("\n Total iterations %d",iterations);
	return (0);
}
