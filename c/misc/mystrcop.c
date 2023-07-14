#include <stdio.h>
#include <conio.h>
#include <string.h>

void strcopy_arr(char d[],char s[])
{
  int i=0;
  while(s[i]!='\0')
  {
	d[i] = s[i];
	i++;
  }
  d[i] = '\0';
}

void strcopy_ptr(char *d,char *s)
{
  while(*s!='\0')
  {
	*d = *s;
	d++;
	s++;
  }
  *d = '\0';
}

void adv_strcopy_ptr(char *d,char *s)
{
    while( (*d++ = *s++) != '\0' );
}


void main()
{
 char source[]="thatsme";
 char destination[10];
  clrscr();

//  strcopy_arr(destination,source);
  strcopy_ptr(destination,source);
//  adv_strcopy_ptr(destination,source);

  printf("%s",destination);

 getch();
}
