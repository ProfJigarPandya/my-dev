/*
 * In a company an employee is paid as under :
If his basic salary is less than Rs. 1500 then HRA=10% of basic salary and DA=90% of basic salary.
If his salary is either equal to or above 1500 then HRA= Rs. 500 and DA=98% of basic salary. Find out employee's gross salary.
Input Format
Input will contain one integer which represents the basic salary of the employee
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int basicSalary;
	scanf("%d",&basicSalary);
	if(basicSalary<1500)
	{
		printf("%f",basicSalary+(basicSalary*0.10)+(basicSalary*0.9));
	}
	else
	{
		printf("%f",basicSalary+(500)+(basicSalary*0.98));
	}

    return 0;
}

