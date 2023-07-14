#include <conio.h>
#include <stdio.h>

 void main(int argc,char *argv[])
 {

  FILE *sourcep,*destp;
  clrscr();


  if(argc != 3)
  {
	printf("\n USAGE : mycopy source destination");
	exit(0);
  }
  //open source file for read
  sourcep = fopen(argv[1],"r");
  if(sourcep == NULL)
  {
	perror("Error : ");
	printf("\n Source file is not present ");
	exit(0);
  }
  // open destination file for write mode
  destp= fopen(argv[2],"w");

  //copy content
  while(!feof(sourcep))
  {
       putc( getc(sourcep), destp);
  }
  fclose(sourcep);
  fclose(destp);



  getch();
 }


