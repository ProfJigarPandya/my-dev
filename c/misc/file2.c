#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *f1,*f2;
	char c;
	clrscr();

	f1=fopen("INPUT","r+");
	f2=fopen("OUTPUT", "w+");

	while((c=getc(f1))!=EOF)
		putc(c,f2);

	rewind(f2);

	while((c=getc(f2))!=EOF)
		printf("%c",c);

	fclose(f1);
	fclose(f2);
	getch();
}
