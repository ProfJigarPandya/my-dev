/* Design a simple calculator which can perform addition, subtraction , multiplication and division on the integer input.
Read two numbers no1 and no2 from user followed by a number op, indicates operation (1-add 2-subtract 3-multiply 4-division) and
implement following operations: 1. Addition 2. Subtraction 3. Multiplication 4. Division
Addition and Subtraction operation should not print any value while multiplication and division should print the answer.
Input Format
no1 no2 operator
Constraints
1<=no1,no2<=10000
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int num1, num2;
	int oper;//a number op, indicates operation (1-add 2-subtract 3-multiply 4-division)
	scanf("%d %d %d",&num1,&num2,&oper);
	switch(oper)
	{
		case 1://addition
		       printf("%ld",num1+num2);
		       break;
		case 2://subtraction
		       printf("%d",num1-num2);
		       break;
		case 3://multiplication
		       printf("%ld",num1*num2);
		       break;
		case 4://division
		       printf("%f",(float)num1/num2);
		       break;
		default:
		       printf("N/A");
	};

    return 0;
}
