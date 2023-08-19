//Implement Simple Calculator using Switch Statement.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int operand1,operand2;
	char opr;
	scanf("%d",&operand1);
	scanf("%d",&operand2);
	scanf(" %c",&opr);

	switch(opr)
	{
		case '+':
			printf("%d",operand1+operand2);
			break;	
		case '-':
			printf("%d",operand1-operand2);
			break;	
		case '*':
			printf("%d",operand1*operand2);
			break;	
		case '/':
			printf("%d",operand1/operand2);
			break;	
		case '%':
			printf("%d",operand1%operand2);
			break;	
		default:
			printf("Not supported.");
			break;	
	};


    return 0;
}

