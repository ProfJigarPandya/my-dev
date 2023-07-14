/* sorting of strings */

#include <stdio.h>
#include <conio.h>
#define MAX 7

void main()
{

 int i,j,n,pass;
 char strings[MAX][MAX];
 clrscr();

  for(i=0;i<MAX;i++)
	scanf("%s",strings[i]);

  /* sorting starts */
  for(pass=1;pass<=MAX-1;pass++)
  {
	for(j=0; j<MAX-pass ;j++)
	{
	 if(strcmp(strings[j],strings[j+1]) > 0 )
	 {
		char temp[MAX];
		strcpy(temp,strings[j]);
		strcpy(strings[j],strings[j+1]);
		strcpy(strings[j+1],temp);
	 }
	}
  }

  /* display sorted data */
  printf("\n");
  for(i=0;i<MAX;i++)
	printf("\n%s",strings[i]);



 getch();
}