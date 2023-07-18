/*Write a program that requests for a file name and an integer, known as offset value. The program then reads the file starting from the location specified by the offset value and prints the contents on the screen. (Support Error handling during I/O operations)*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXFN 100
int main()
{
 char filename[MAXFN];
 long offset;
 int sizeinbytes, c, status;
 FILE *fp;


 printf("\n Enter a file name");
 scanf("%s",filename);	

 printf("\n Enter offset to start reading the file from. (any number)");
 scanf("%d",&offset);

 fp=fopen(filename, "r");
 if(fp==NULL)
 {
	printf("\n Error in opening file: errno:%d ErrorMessage: %s",errno, strerror(errno));
	exit(EXIT_FAILURE);
 }

 status=fseek(fp, offset, 0);

 if(!status)//fseek suppose to return -1 but lets accept that it returns false if failed.
 {
	printf("\n Offset provided is beyond the file capacity ");
	exit(1);
 }
 
 printf("\n Required output : \n");
 while((c=getc(fp))!=EOF)
 {
	putc(c,stdout);
 }

 return(0);
}
