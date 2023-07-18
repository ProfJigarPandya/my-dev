/* main.c */
/*
  Program to print factorials of all integers
  between 0 and 20
*/

#include <stdio.h>
#include "factorial.h"
#include "test.h"

/* Prototype for fucntion factorial() */
void factorial();    

/* Global variable declarations */
int j;               
double fact;
static double sfact;
int main() 
{
  /* Print factorials of all integers between 0 and 20 */
  for (j = 0; j <= 20; ++j)
    {
      factorial();
 
      printf("j = %3d    factorial(j) = %12.3e\n", j, fact);
    }

   printf("To learn that global static can be restricted to be used by file in which it is declared/defined. %12.3e \n",sfact);
   printf("To learn that global static can be restricted to be used by file in which it is declared/defined. %12.3e \n",givedata());
  return 0;
}
