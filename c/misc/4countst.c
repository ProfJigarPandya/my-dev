#include <conio.h>
#include <stdio.h>

 void main(int argc,char *argv[])
 {

  FILE *fp;
  char arr[50];
  int count=0;
  clrscr();


  if(argc != 3)
  {
	printf("\n USAGE : findrep file find");
	exit(0);
  }
  //open source file for read
  fp = fopen(argv[1],"r");
  if(fp == NULL)
  {
	perror("Error : ");
	printf("\n Source file is not present ");
	exit(0);
  }


  while(!feof(fp))
  {
       fscanf(fp,"%s",arr);
       if( strcmp(arr,argv[2]) == 0 )
       {

	 count++;
       }
  }
  fclose(fp);

  printf("\n String found %d time ",count);

  getch();
 }


