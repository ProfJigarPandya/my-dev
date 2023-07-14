#include<stdio.h>
#include<conio.h>

void main()
{

	FILE *fp1,*fp2;
	char name[20];
	int age;

	clrscr();

	fp1 = fopen("SRC","w");

	scanf("%s%d", name,&age);
	fprintf(fp1,"%s%d",name,age);

	fclose(fp1);

	fp1 = fopen("SRC","r");
	fp2 = fopen("DES","w");

	fscanf(fp1,"%s%d",name,&age);
	fprintf(fp2,"%s%d",name,age);

	fclose(fp1);
	fclose(fp2);

	fp2 = fopen("DES","r");

	fscanf(fp2,"%s%d",name,&age);
	fprintf(stdout,"%s%d",name,age);


	getch();
}


