#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *f1;
	char c[10];
	int i;
	float f;

	clrscr();

	f1=fopen("INPUT","w");

	printf("Enter data");
	fscanf(stdin,"%s%d%f",c,&i,&f);
	fprintf(f1,"%s %d %f",c,i,f);

	fclose(f1);

	f1=fopen("INPUT","r");
	printf("Data you have entered\n");
	fseek(f1,-1,2);
	fscanf(f1,"%s%d%f",c,&i,&f);
	fprintf(stdout,"%s  %d  %f",c,i,f);

	fclose(f1);


	getch();
}
