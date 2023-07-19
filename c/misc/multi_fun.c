#include <stdio.h>
void printline(char ch)
{
	int i;
	printf("\n");

	for(i=1;i<=30;i++)
		printf("%c",ch);
		
	printf("\n");
}
void printHeader()
{
	printf(" \n MULTIPLICATION TABLE \n");
	printf(" \n element of the table indicates multiplication of row with column index. \n");

}
int main()
{
	int i,j;
	printHeader();
	printline('*');

	printline('-');
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			printf("%3d",i*j);
		}
		printline('-');
	}
	
	printline('*');
	
}
