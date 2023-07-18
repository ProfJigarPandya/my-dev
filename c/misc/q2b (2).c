#include <stdio.h>
#include <stdlib.h>

int countOccur ( int digit, int number)
{
    if( (digit<0 && digit>9) || (number<0))
    {
      printf("\n Eighter number is negative or digit has more digits then 1."); 
      exit(1);
    }
    if (number==digit)
          return 1;
    else if( 0<=number && number<=9) //number is of single digit but not matching
	  return 0; 
    else if( (number%10) == digit)
            return( 1 + countOccur (digit, number/10));
    else
           return( 0 + countOccur(digit, number/10));
}
int main()
{
 printf("\nOccurrence of digit 0 in number 0 is %d\n",countOccur(0,0));
 printf("\nOccurrence of digit 0 in number 5 is %d\n",countOccur(0,5));
 printf("\nOccurrence of digit 1 in number 1 is %d\n",countOccur(1,1));
 printf("\nOccurrence of digit 1 in number 7 is %d\n",countOccur(1,7));
 printf("\nOccurrence of digit 0 in number 1000 is %d\n",countOccur(0,1000));
 printf("\nOccurrence of digit 0 in number 1312 is %d\n",countOccur(0,1312));
 printf("\nOccurrence of digit 1 in number 1000 is %d\n",countOccur(1,1000));
 printf("\nOccurrence of digit 1 in number 1312 is %d\n",countOccur(1,1312));
 printf("\nOccurrence of digit 2 in number 1312 is %d\n",countOccur(2,1312));
 printf("\nOccurrence of digit 2 in number 21212 is %d\n",countOccur(2,21212));
 printf("\nOccurrence of digit 2 in number 1314 is %d\n",countOccur(2,1314));
 
}

