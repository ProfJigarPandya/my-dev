#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
 char *str[]={"abc","ab","de","re","ef"};
 int i,j;

 clrscr();
 for(i=0;i<4;i++)
 {
  for(j=i;j<5-i-1;j++)
  {
    if(strcmp(str[j],str[j+1])>0)
    {
	char *temp;
	temp = str[j];
	str[j]=str[j+1];
	str[j+1]=temp;
    }
  }
 }

 for(i=0;i<5;i++)
	printf("\n%s",str[i]);




 getch();
}