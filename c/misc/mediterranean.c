//mediterranean - secret message using pointer arithmetic
#include <stdio.h>
#include <string.h>


int main()
{
	char key[][3]={"1","8","3","2","5","11","6","7","0","10","9","4","12"};
	int i;
	char secretdata[]="eaidearrmentn";//mediterranean
	char message[14];
	for(i=0;i<strlen(secretdata);i++)
	{
		//printf("\n%c",data[atoi(key[i])]);
			
		message[atoi(key[i])]=secretdata[i];
	}
	message[strlen(secretdata)]='\0';
	puts(message);
	return(0);
}

