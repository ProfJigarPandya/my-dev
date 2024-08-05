#include <stdio.h>
int main()
{
	int i;
	printf("\n 1 to 10 except 5 using for. Note that i++ is performed evertytime, does not matter regular way repeat or continue way repeat. \n");
	for(i=1;i<=10;i++)
	{
		if(i==5)
		{
			continue;
		}
		printf("%d\t",i);
	}

	printf("\n 1 to 10 except 5 using while.. correct. \n");
	i=1;
	while(i<=10)
	{
		if(i==5)
		{
			i++;
			continue;
		}
		printf("%d\t",i);
		i++;
	}

	printf("\n 1 to 10 except 5 using while.. incorrect.\n This will result in infinite loop because i forever stays 5 itself.\n");
	i=1;
	while(i<=10)
	{
		if(i==5)
		{
			continue;
		}
		printf("%d\n",i);
		i++;
	}
}

