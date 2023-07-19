#include<stdio.h>
#include<conio.h>

struct student
{
	char name[10];
	int rollno;
	int marks;
};

void main()
{
	struct student s1 = {"abc",111,98};
	struct student s2 = {"xyz",112,97};
	struct student s3;
	int x;

	clrscr();

	s3 = s2;

	x = ((s3.rollno == s2.rollno) && (s3.marks == s2.marks))?1:0;

	if(x==1)
	{
		printf("\nstudent2 and student3 are same");
		printf("  %s  %d  %d  ",s3.name,s3.rollno,s3.marks);
	}
	else
		printf("\n student2 and student3 are not same");

	getch();
}