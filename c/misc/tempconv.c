/* use of #define   ...........

 and formatting display output in tabular...form..
 */

#include<stdio.h>
#include<conio.h>


#define F_LOW 0
#define F_MAX 250
#define STEP 25

void main()
{

	float fahrenheit, celsius;
	clrscr();

	fahrenheit = F_LOW;

	printf("Fahrenheit	Celcius\n\n");

	while(fahrenheit <= F_MAX)
	{
		celsius = (fahrenheit - 32.0)/1.8;
		printf("%5.1f		%7.2f\n",fahrenheit,celsius);
		fahrenheit = fahrenheit + STEP;
	}


	printf("\n reverse order \n");

	fahrenheit = F_MAX;
	while(fahrenheit >= F_LOW)
	{
		celsius = (fahrenheit - 32.0)/1.8;
		printf("%5.1f		%7.2f\n",fahrenheit,celsius);
		fahrenheit = fahrenheit - STEP;
	}

	getch();
}

