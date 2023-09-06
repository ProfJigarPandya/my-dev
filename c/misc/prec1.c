#include <stdio.h>
//Note that below is for helping upto certain step only. Few steps still need to be read, remembered and applied as per book/official table.

//PUMAS REBL TAC
//P - Parenthesis
//U - Unary
//M - Multiplication
//Af - Addition
//S - Shift
//R - Relational
//E - EqualEqual/Not equal
//B - Bitwise
//L - Logical
//T - Turnary/Conditional
//Al - Assignment
//C - Comma

int main()
{
	//Example1
	printf("%d\n",8+4-(2+1)*3%5+20/9);//P
	printf("%d\n",8+4-3*3%5+20/9);//M
	printf("%d\n",8+4-9%5+20/9);//M
	printf("%d\n",8+4-4+20/9);//M
	printf("%d\n",8+4-4+2);//A
	printf("%d\n",12-4+2);//A
	printf("%d\n",8+2);//A
	printf("%d\n",10);
	printf("%d\n",8+4-(2+1)*3%5+20/9);
	
}
