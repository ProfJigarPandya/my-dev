#include <stdio.h>
int main()
{
	int i=5;
	while(i>0)
	{
		printf("Value of i is %d\n",i);
		if(i==3)
			break;
   		else
			continue;
   		i=i-1;
 	}
	printf("Value of i is %d\n",i);
	return 0;
}
