#include <stdio.h>
int atoi(char ar[])
{
 int res=0,i=0;
	while(ar[i]!='\0')
	{
	  res = res*10 + (ar[i]-'0');
	  i++;
	}
 return res;
}
int main()
{
	char arr[]={'2','3','4','\0'};
	int i=0,res;

	printf("%d",atoi(arr));

	return 0;
}
