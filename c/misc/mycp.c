//Copy source file to destination file using command line arguments
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ch;
	FILE *finput,*foutput;
	if(argc!=3)
	{
		printf("Usage: mycp source dest \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("You ran command %s %s %s\n", argv[0],argv[1],argv[2]);
	}
	finput=fopen(argv[1],"r");
	foutput=fopen(argv[2],"w");
	if(finput==NULL || foutput==NULL)
	{
		printf("Either source or destination not accessible\n");
		exit(EXIT_FAILURE);
	}

	while((ch=getc(finput))!=EOF)
	{
		putc((char)ch,foutput);
	}
	
	fclose(finput);
	fclose(foutput);
	
	printf("File copied successfully\n");	
	return (EXIT_SUCCESS);
}
