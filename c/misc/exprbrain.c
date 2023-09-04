/*
Add arithmetic operators (plus, minus, times, divide) to make the following expres-
sion true: 3 1 3 6 = 8 You can use any parentheses you’d like

To learn float vs integer arithmetic. How to create user defined datatype using enum. exit/return status of main goes to operating system.
Non-zero expression value is true. Zero is false.
Zero return status to linux os means success. Non-zero is failre.
*/

#include <stdio.h>
#include <stdlib.h>

enum boolean {FALSE,TRUE};

int main()
{
	
	float af=3,bf=1,cf=3,df=6;
	int ia=3,ib=1,ic=3,id=6;
	enum boolean flag=FALSE;
	float res=0;

	system("clear");

	res = (af + bf) / cf * df ;
	printf("\n Result of float arithmetic %f",res);

	if (res==8)
		flag=TRUE;

	if(flag)
		printf("\n Float arithmetic : You got it right ");
	else
		printf("\n Float arithmetic : You may not see this, if arithmetics is float arithmetic.");

	flag=FALSE;

        res = (ia + ib) / ic * id ;
        printf("\n Result of integer arithmetic %f",res);

        if (res==8)
		flag=TRUE;

	if(flag)
		printf("\n Integer arithmetic : Integer arithmetic  match to 8.");
	else
		printf("\n Integer arithmetic : Integer arithmetic did not match to 8");
	
	printf("\n");

	return EXIT_SUCCESS;
}

