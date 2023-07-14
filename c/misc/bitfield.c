
#include <conio.h>
#include <stdio.h>

enum M_STATUS {MARRIED,UNMARRIED};
enum GENDER {MALE,FEMALE};

 struct person
 {
   char name[10];
   unsigned int age:7;
   unsigned int gender:1;
   unsigned int marital_status:1;
   float salary;
 };
 void display(struct person p)
 {
   printf("\n %10s %3d %12s %12s %5.2f",p.name,p.age,p.gender==0?"MALE":"FEMALE",p.marital_status==0?"MARRIED":"UNMARRIED",p.salary);
 }

 void main()
 {
  struct person p1={"john",34,MALE,MARRIED,10000.00};
  struct person p2={"lio",22,MALE,UNMARRIED,20000.00};
  struct person p3={"mary",21,FEMALE,MARRIED,30000.00};


  clrscr();

  display(p1);
  display(p2);
  display(p3);

  getch();
 }


