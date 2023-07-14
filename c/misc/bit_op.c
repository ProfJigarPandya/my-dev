#include <stdio.h>
#include <conio.h>

void main()
{
 int x=16; // 00000000 00010000

 clrscr();

// Bitwise AND    &

 printf("\n AND %d",x&1); // 00000000 00010000      &
		   // 00000000 00000001

	   // Result  00000000 00000000   = zero in decimal



// Bitwise OR    |

 printf("\n OR    %d",x|1); // 00000000 00010000    |
		   // 00000000 00000001

	   // Result  00000000 00010001   = 16+1 = 17  in decimal



// Bitwise EX OR    ^
// 1 ^ 0 = 1      0 ^ 1 = 1          any other 0
 printf("\n EX OR    %d",x^21); // 00000000 00010000    ^
				// 00000000 00010101

		       // Result  00000000 00000101   = 4+1 = 5  in decimal


// Shift Left              variable  <<  no of times

 printf("\n shift left    %d",x<<2); // 00000000 00010000    <<   2
				   //   00000000 01000000

		       // Result  00000000 01000000    64     2 raise to 6

  // It do not modify the original variable ......
  printf("\n shift left    %d",x);


  // Right shift twice
  x=x>>2;                            /// divis
  printf("\n the new value %d ",x);


 getch();
}