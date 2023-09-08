//Validating input password for minimum security requirements as below:
//Must have atleast one upper case letter
//Must have atleast one lower case letter
//Must have atleast one digit
//Must have atleast one punctuation/symbol
//Must be of lenght 8 or more

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MINLEN 8
enum boolean {FALSE,TRUE};

int main()
{
	char ch;
	enum boolean 	yUpper=FALSE, 
			yDigit=FALSE,
			ySymbol=FALSE,
			yLower=FALSE,
			yValidPass=FALSE
		;
	int chCount=0;

	printf("Please, enter password for validating minimum requirements: ");
	
	do
	{
		ch = getchar();

		if(yValidPass)
			continue;

		if( !yUpper && isalpha(ch) && isupper(ch))
			yUpper=TRUE;
		else if(!yLower && isalpha(ch) && islower(ch))
			yLower=TRUE;
		else if(!yDigit && isdigit(ch))
			yDigit=TRUE;
		else if(!ySymbol && ispunct(ch))
			ySymbol=TRUE;
			

		chCount++;
		//printf("\t%d\t\n",chCount);
		if( yUpper && yLower && ySymbol && yDigit && (chCount>=MINLEN ) )
		{
			yValidPass=TRUE;
		}

	}while(ch!='\n');
	

	if(yValidPass==TRUE)
		printf("Congratulations, your password is having enough robustness.\n");
	else	
	{
		printf("Please, try another password. Current password doesn't match the security requirement criteria.");
		if(!yUpper)
			printf("\n You need atleast one upper case alphabet.");
		if(!yLower)
			printf("\n You need atleast one lower case alphabet.");
		if(!yDigit)
			printf("\n You need atleast one digit.");
		if(!ySymbol)
			printf("\n You need atleast one symbol/puncuation mark.");
		if(chCount<=MINLEN)
			printf("\n You need atleast %d length of input password not including the enter key at the end.",MINLEN);
		printf("\n");
	}
	
	
	return 0;
	
}
