/*
 need to store information of 10 person........

	includes...... name
		       age

		       FOR AGE  condition is
	      -> above 60 years store         status as 'R' for retired
	      -> inbetween 20 to 60 write  age in years....
	      -> below 20 write birth date like 23/04/1999  ... a string


.............SAVE MEMORY .......

*/

#include<stdio.h>
#include<conio.h>

union AGE
{
	char bdate[11];
	char status;
	int years;
};

struct person
{
	char name[15];
	short int utype;
	union AGE age_of_person;
};

void display(struct person);

void main()
{

	struct person p1={"james",1,{"20/03/1999"}},p2={"hardy",2,{40}},p3={"john",3,{'r'}};

	clrscr();
	display(p1);
	display(p2);
	display(p3);
	getch();
}

void display(struct person p)
{

  printf("\n");
  printf("Name : %s",p.name);
  if(p.utype == 1)
    printf("  of  : %s",p.age_of_person.bdate);
  else if(p.utype == 2)
    printf(" of : %d",p.age_of_person.years);
  else
    printf("  of : %c",p.age_of_person.status);
}