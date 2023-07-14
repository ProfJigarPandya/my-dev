#include <stdio.h>
#include <conio.h>
#include <string.h>

void mystrrev(char *str)
{
 int num,i=0;
 char temp;
  num = strlen(str);
  num--;
  while(i < (num/2))
  {
   temp = *(str+i);
   *(str+i) = *(str+num-i);
   *(str+num-i) = temp;
   i++;
  }
}
void main()
{
 char str[]="abcde";
 clrscr();

 mystrrev(str);
 printf("%s",str);
 getch();
}