#include <stdio.h>
struct estore
{
	char s_name[8];
	struct department
	{
		char d_name[8];
		struct product
		{
			char p_name[8];
			float price;
		}p[100];
	}d[10];
}e[5];
int main()
{
	printf("\n Size of e is %d ",sizeof(e));
	printf("\n Size of e[0] is %d ",sizeof(e[0]));//size of single estore is  12088
	printf("\n Size of e[0].d[0] is %d ",sizeof(e[0].d[0])); //size of single department is 1208
	printf("\n Size of e[0].d[0].p[0] is  %d ",sizeof(e[0].d[0].p[0])); //size of single product 12
	
}
