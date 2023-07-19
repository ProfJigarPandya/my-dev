#include <stdio.h>
#include <stdlib.h>

//q1ei.c:8: error: expected ‘:’ before ‘;’ token
//Instead of using colun :, user typed semicolon

//q1ei.c: In function ‘value’:
//q1ei.c:11: error: expected expression before ‘return’
//Because return is not an expression and hence turnary operator shows error. Actually because return actually is unconditional jump to the caller.


int value(int a)
{
	//a>20 ? return (10) ; return(20);
	//a>20 ? return (10) : return (20);
	a>20 ? printf("10") : printf ("20");

	/*if(a>20)
		return (10);
	else 
		return (20);*/
	return -1;
}
void main()
{
	int a=value(20);
	printf("%d",a);
}
