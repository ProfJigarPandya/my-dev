/* concatenation of strings in third....

  string1 = {"James"};

  want to copy string1 to  string2

  So, that after copying string2 should also be "James"
*/
#include <stdio.h>
#include <conio.h>

void main()
{

char string1[6]="James";
char string2[6];
int i,j;
clrscr();



for(i=0;string1[i]!='\0';i++)
{
 string2[i] = string1[i];
}
string2[i] = '\0';


/*
i=0;
while((string2[i++]=string1[i])!='\0');
*/

printf("\n String2   :%s",string2);
getch();
}
