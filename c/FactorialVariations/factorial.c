/* factorial.c */
/* 
   Function to evaluate factorial (in floating point form)
   of non-negative integer j. Result stored in variable fact.
*/

#include <stdio.h>
#include <stdlib.h>

/* Global variable definitions */
extern int j;               
extern double fact;
extern double sfact;
void factorial() 
{
  int count;

  /* Abort if j is negative integer */
  if (j < 0) 
    {
      printf("\nError: factorial of negative integer not defined\n");
      exit(1);
    }

  /* Calculate factorial */
  for (count = j, fact = 1.; count > 0; --count) fact *= (double) count;

  sfact=100;

  return;      
}
