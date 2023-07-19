#include <stdio.h>
#include <conio.h>

int myfun()
{

 static int st_count=0;
 int count=0;

 st_count++;
 count++;

 printf("\n static  %d         auto count %d",st_count,count);

 return st_count;
}

void main()
{
 int n;
 clrscr();

 myfun();
 myfun();
 myfun();
 myfun();
 n=myfun();

 printf("\n function is called ... %d times ",n);

 getch();
}

