#include<stdio.h>
#include<conio.h>

struct student
{
	char name[20];
	int rollno;
	float marks;
};

void main()
{
	struct student s;

	clrscr();

	printf("Input values");
	scanf("%s%d%f",s.name,&s.rollno,&s.marks);

	printf("%s	%d	%f",s.name,s.rollno,s.marks);

	getch();

}

