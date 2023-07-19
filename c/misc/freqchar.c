/* to find the frequency of a character from a string  */

#include <stdio.h>
#include <conio.h>
int findfreq(char str[],char ch)
{
  int freq=0;
  int i=0;
  while(str[i]!='\0')
  {
	if(str[i]==ch)
		freq++;
	i++;
  }
  return freq;
}

void main()
{
char string[10];
char ch;
int n;
clrscr();

 printf("\n Enter string ");
 scanf("%s",string);

 fflush(stdin);

 printf("\n Enter the character");
 scanf("%c",&ch);

 n=findfreq(string,ch);

 printf("\n The character occurs %d times ",n);


 getch();
}