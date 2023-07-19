/*
Develop a command line arguments supported program to open and display content of binary files containing list of integers. The file names are provided at command line.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	int i,j;
	int number, times;
	if(argc==0)
	{
		printf("\nUsage: mycat file1 file2 file3 ..");
		exit(1);
	}	
	
	
	
	for(i=1;i<argc;i++)
	{
		//logic to create binary files [optional]
		fp=fopen(argv[i],"w");
                if(fp==NULL)
                {
                        printf("\n Error in opening file %s", argv[i]);
                        continue;
                }
		srand(time(0));
		times=random()%50+1;
		
		j=0;
		while(j<times)
		{
			putw((int)random()%10,fp);
			j++;
		}
		fclose(fp);
		

		fp=fopen(argv[i],"r");
		if(fp==NULL)
		{
			printf("\n Error in opening file %s", argv[i]);
			continue;
		}
		printf("\n%s contents:\n",argv[i]);
		while((number=getw(fp))!=EOF)
		{
			printf("\t%d",number);
		}	
		fclose(fp);	
	}

		
}
