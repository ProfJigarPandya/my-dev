/*
   d1     =     2' 7"
   d2	  =     5' 9"

   d3    =    d1 + d2  =        8' 4"

		 if addition of inches greater equat to 12 than
		  convert it to feet and remaining  will be the inches....

*/

#include <stdio.h>
#include <conio.h>

struct Distance
{
  int feet;
  float inches;
};

/* add two distances and display the result in the function itself... */
void adddistance(struct Distance one,struct Distance two)
{
  struct Distance temp;

  temp.inches = one.inches + two.inches;
  temp.feet = one.feet + two.feet;

  if( temp.inches >= 12 )
  {

    temp.inches = temp.inches - 12;
    temp.feet = temp.feet + 1;
  }
  printf("Addition  : %d\'  %f\" ",temp.feet,temp.inches);
}
  /* with return   */
struct Distance ret_addition(struct Distance one,struct Distance two)
{
  struct Distance temp;

  temp.inches = one.inches + two.inches;
  temp.feet = one.feet + two.feet;

  if( temp.inches >= 12 )
  {

    temp.inches = temp.inches - 12;
    temp.feet = temp.feet + 1;
  }

  return temp;
}


struct Distance ret_just(struct Distance d1,struct Distance d2)
{
  d1.inches = d1.inches + d2.inches;
  d1.feet = d1.feet + d2.feet;

  if( d1.inches >= 12 )
  {
    d1.inches = d1.inches - 12;
    d1.feet = d1.feet + 1;
  }

  return d1;
}

void main()
{
 clrscr();
 struct Distance d1,d2,d3;
 printf("\n enter values for distance1 ");
 scanf("%d%f",&d1.feet,&d1.inches);

 printf("\n enter values for distance2 ");
 scanf("%d%f",&d2.feet,&d2.inches);
 /******************/

  adddistance(d1,d2);


  /***********/
  d3 = ret_addition(d1,d2);
  printf("\n  Addition  : %d\'  %f\" ",d3.feet,d3.inches);

  /**********/
  d3 = ret_just(d1,d2);

  printf("\n  Addition  : %d\'  %f\" ",d3.feet,d3.inches);

  printf("\n  Addition  : %d\'  %f\" ",d1.feet,d1.inches);

 getch();
}

