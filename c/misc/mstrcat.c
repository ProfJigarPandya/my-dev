/* concatenation of strings in third....
  string1 = {"James"};
  string2 = {"Bond"};


  string3 should be  "james Bond"
*/
#include <stdio.h>
#include <conio.h>

void main()
{
char string1[]="James";
char string2[]="Bond";
char string3[11];
int i,j;
clrscr();

// copy the string1 into string3
for(i=0;string1[i]!='\0';i++)
	string3[i] = string1[i];

// concatenate the string2 at the end of  string3
string3[i++] = ' ';

for(j=0;string2[j]!='\0';j++)
{
	string3[i] = string2[j];
	i++;
}

string3[i] = '\0';

printf("\n String3   :%s",string3);
getch();
}
