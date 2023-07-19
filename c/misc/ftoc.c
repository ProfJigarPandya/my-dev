#include <stdio.h>
#include <conio.h>

#define F_LOW 0
#define F_HIGH 250
#define STEP 25


void main()
{
 typedef float REAL;
 REAL fahrenheit,celsius;

 clrscr();
 fahrenheit = F_LOW;

 printf(" FAHRENHEIT		CELSIUS		");
 while(fahrenheit<=F_HIGH)
 {
	celsius = (fahrenheit - 32 ) / 1.8;
	printf("\n %5.2f                %7.2f  ",fahrenheit,celsius);
	fahrenheit+=STEP;
 }

 getch();
}
