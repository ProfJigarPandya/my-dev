#include <stdio.h>

void foo(int n, int sum);
int bar(int n, int sum);
int main()
{
	int a = 2048;
	int foosum=0;
	foo(a,foosum);
	printf("%d\n",foosum);
	int barsum=0;
	barsum=bar(a,barsum);
	printf("%d\n",barsum);


	return 0;
}

void foo(int n, int sum)
{
	int k=0,j=0;
	if(n==0)
	{
		return;
	}

	k=n%10;
	j=n/10;
	sum=sum+k;
	foo(j,sum);
	printf("%d",k);
	return;
}
int bar(int n, int sum)
{
	int k=0,j=0;
	if(n==0)
	{
		return(sum);
	}

	k=n%10;
	j=n/10;
	sum=sum+k;
	sum=bar(j,sum);
	printf("%d",k);
	return sum;
}
