#include<stdio.h>
#include<conio.h>

struct student
{
	int sub1;
	int sub2;
	int sub3;
	int total;
};

void main()
{
	struct student student[3] = {{40,50,60,0},{50,60,70,0},{60,70,80,0}};
	struct student total={0,0,0};
	int i;

	clrscr();

	for(i=0;i<=2;i++)
	{
		student[i].total = student[i].sub1+student[i].sub2+student[i].sub3;
		total.sub1 = total.sub1 + student[i].sub1;
		total.sub2 = total.sub2 + student[i].sub2;
		total.sub3 = total.sub3 + student[i].sub3;
		total.total = total.total + student[i].total;

	}

	printf("STUDENT		TOTAL\n\n");
	for(i=0;i<=2;i++)

		printf("Student[%d]		%d\n",i+1,student[i].total);

	printf("\n\nSTUDENT		TOTAL\n\n");

	printf("Subject1         %d",total.sub1);
	printf("\nSubject2         %d",total.sub2);
	printf("\nSubject3         %d",total.sub3);

	printf("\n\n GRAND TOTAL = %d",total.total);


	getch();
}