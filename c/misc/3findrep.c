#include <conio.h>
#include <stdio.h>

 void main(int argc,char *argv[])
 {

  FILE *fp;
  char arr[50];
  int count=0;
  clrscr();


  if(argc != 4)
  {
	printf("\n USAGE : findrep file find replace");
	exit(0);
  }
  //open source file for read
  fp = fopen(argv[1],"r+");
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
	 fseek(fp,-(strlen(arr)),1);
	 fprintf(fp,"%s",argv[3]);
	 fseek(fp,strlen(arr),1);
	 count++;
	 fflush(fp);
       }
  }
  fclose(fp);

  printf("\n String found %d time ",count);

  getch();
 }


