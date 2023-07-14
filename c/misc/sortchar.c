/* sorting of characters

i.e if input is
	any string contaning abcd...xyz. in random.

	the output will be abcdef.......in alphabetic order.

*/
#include <stdio.h>
#include <conio.h>

void main()
{
 char str[50]="dcbaded";
 int i,j,n=strlen(str);
 clrscr();

 for(i=0;i<n-1;i++)
 {
   for(j=0;j<n-1-i;j++)
   {
     if(str[j]>str[j+1])
     {
	char temp;
	temp = str[j];
	str[j] = str[j+1];
	str[j+1] = temp;
     }
   }
 }
 printf("In alphabetic \n %s ",str);

 getch();
}