/* convert decimal to binary... */
//This output needs to read from right to left. This is not a true solution for decimal to binary.
#include <stdio.h>


void main()
{
 int x=16;

 while(x>=1)
 {
	printf("%d",x%2);
	x=x/2;
 }
}
