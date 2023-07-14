/* pelindrom string */

#include <stdio.h>
#include <conio.h>

void main()
{
char str1[10],str2[10];
int i,n,j;
clrscr();

printf("\n enter string ");
i=0;
while( ( str1[i] = getchar() )    != EOF)
{
   i++;
}

n=i;
i--;

for(j=0;j<n;j++)
{
  str2[j]=str1[i];
  i--;
}

for(i=0;i<n;i++)
{
	if(str1[i] != str2[i])
		break;
}

if(i==n)
	printf("\n String is Pelindrome ");
else
	printf("\n String is not ");



getch();
}