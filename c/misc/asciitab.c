//Display ascii table
#include <stdio.h>

void main()
{
 int i;
 for(i=0;i<128;i++)
 {    
	if(i%4 == 0)
	    printf("\n");
	printf("|   %3d   %c   |",i,i);
 }
 getchar();
}
