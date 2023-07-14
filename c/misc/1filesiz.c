#include <conio.h>
#include <stdio.h>

 void main()
 {
  FILE *fp;
  clrscr();
  fp = fopen("hello.txt","r");
  if(fp == NULL)
  {
	perror("Error : ");
	getch();
	exit(0);
  }
  fseek(fp,0,2);
  printf("size of a file %d ",ftell(fp));
  getch();
 }


