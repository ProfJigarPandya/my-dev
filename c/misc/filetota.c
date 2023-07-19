#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *fp;
	int number;
	int total = 0;

	clrscr();

	fp = fopen("INPUT","w");

	printf("\nEnter number(Enter -1 to stop)\n");

	while(number != -1)
	{
		scanf("%d",&number);
		putw(number,fp);
	}



	fclose(fp);

	fp = fopen("INPUT","r");

	while((number = getw(fp)) != EOF)
		total+=number;

	printf("Total = %d",total);

	getch();
}
