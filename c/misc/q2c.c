/*
ii.Write a program to find total number of bytes in ‘demo.txt’ file, without using any input/output operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
 FILE *fp;
 fp=fopen("demo.txt", "r");
 int status, n;
 if(fp==NULL)
 {
	printf("\n File opening error. ErrNo %d and ErrorMessage %s" , errno, strerror(errno));
	return(1);
 }
 
 status=fseek(fp, 0L,2);//0 on success
 if(!status)
 {
	 n=ftell(fp);
	 printf("\n Total bytes size of demo.txt is %d ",n);

 }
 
}

