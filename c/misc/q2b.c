/*recoreds.dat” file contains lne by line record of teachers. Print record of teacher for whom id is provided in the list of command line arguments. Input is expected in incremental order only. (Support Error handling during I/O operations)*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


#define MAXLENNAME 100

enum boolean {false, true};
void remainingCmds(FILE *fp, char *argv[], int argc, int i);
int main(int argc, char *argv[])
{

 int i,cmd_id;
 int filerec_id,salary,ret;
 char name[MAXLENNAME];
 FILE *fp;

 if(argc<2)
 {
	printf("\n Usage: ./a.out <idx> <idy> <idz> ... \n");
	return(1);
 }
 else
 {
	//printf("\n At most %d number of cmd ids need print ", argc-1);
 }	

 fp=fopen("records1.dat","r");
 if (fp==NULL)
 {
	printf("\n File opening error. Error # %d and Error Message %s ",errno, strerror(errno));
	return(1);
 } 
 
 i=1;

int moveNextRecord = true;
while(i<argc)
{
 	cmd_id = atoi(argv[i]);
	if(moveNextRecord==true)
		fscanf(fp, "%d  %s  %d",&filerec_id,name,&salary);
	
	remainingCmds(fp,argv, argc, i);

	//printf("\n filerecid %d and cmd_id %d and loop control %d",filerec_id, cmd_id, i);
	if(filerec_id==cmd_id)
 	{
		printf("\n%d %s %d", filerec_id, name, salary);
		moveNextRecord=true;
		i++;
	}
	else if(filerec_id<cmd_id)// current filerec_id is not required to be printed. Move to next record.
	{
		moveNextRecord=true;	
	}
	else //current cmd_id is not available in file as a record. Print msg. Move to next cmd.
	{
		printf("\n *** Cmd ID %d not present in the file ", cmd_id);
		moveNextRecord=false;
		i++;
	}
 };

 printf("\n Have a nice day!");

 return(0);
}
void remainingCmds(FILE *fp, char *argv[], int argc, int i)
{
	if(feof(fp))
	{	
		printf("\n *** End of file detected. \n *** For following ids can't printed. \n");
		for(;i<argc;i++)
		{
			printf("\t%s",argv[i]);			
		}
		exit(1);
	}
}

