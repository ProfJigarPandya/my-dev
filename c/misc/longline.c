#include <stdio.h>
#include <conio.h>

#define MAXLINE 50
int flag=0;
int getline(int s[])
{
  int len=0;

  while(1)
  {
       s[len++]=getchar();
       if(len-1 == MAXLINE-1)
	 break;
       else if(s[len-1] == '\n')
	 break;
       else if(s[len-1]==EOF)
       {
	 flag=1;
	 break;
       }
  }
  s[len]='\0';
  return len;
}
void copy(char sou[],char des[])
{
	int i=0;
	while( (des[i++]=sou[i])!='\0');
	return;
}
void main()
{
 int len,longlen;
 char s[MAXLINE],l[MAXLINE];

 clrscr();
 longlen = getline(s);
 copy(s,l);

 if(longlen!=-1)
 {
   while(flag!=1)
   {
    len=getline(s);
       if(len > longlen)
       {
	longlen = len;
	copy(s,l);
	}
   }
 }
 printf(" longest line is \n %s",l);




getch();
}