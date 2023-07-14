#include<stdio.h>
#include<conio.h>


void main()
{
	FILE *fp;
	char c;
	clrscr();

	printf("\n\n DATA INPUT \n\n");
	fp = fopen("INPUT","w");

	while((c=getchar())!=EOF)
		putc(c,fp);

	fclose(fp);

	fp = fopen("INPUT","r");

	while((c=getc(fp))!=EOF)
		printf("%c",c);

	fclose(fp);

	getch();
}