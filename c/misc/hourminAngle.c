//Program to find angle between hour hand and minute hand at a given time
/* Jigar.M.Pandya
   Date: 13/01/2014

Approach: Start with an example like 3:27 We can draw a picture of a clock by selecting
where the 3 hour hand is and where the 27 minute hand is
By playing around with these examples, we can develop a rule:
»    Minute angle (from 12 o’clock): 360 * minutes / 60
	If in 60 minutes minute hand travels 360 degree
	then in 1 z minutes how much?
	
	Ans is 360 * z minutes / 60

»    Hour angle (from 12 o’clock): 

        360 * (hour % 12) / 12 + 360 * (minutes / 60) * (1 / 12)
	This is divided into two parts:

	If in 12 hours hour hand travels 360 degree
	then in x hour how much ?    

	Ans is 360 * hour / 12 ;
		hour % 12 is done just to make it valid for inputs like 15.27
	
	Another for top minutes,
	If in 60 minutes hour hand travels 360/12 degree
        then in y minutes how much ?


	Ans is 360 * 1/12  * y minutes / 60

     

»    Angle between hour and minute: (hour angle - minute angle) % 360
By simple arithmetic, this reduces to 30 * hours - 5 5 * minutes

Here % 360 is performed to round back result within 0-360.


*/

#include <stdio.h>
int main()
{
	int hour, min;
	float angle, hangleA, hangleB, mangle;

	printf("Enter hour(s)");
	scanf("%d",&hour);
	
	printf("Enter minute(s)");
	scanf("%d",&min);

	hangleA = 360 * ((int) hour % 12) / 12 ;
	hangleB = 360 * ( (float) min / 60) * ((float) 1 / 12);
	
	mangle = 360 * (float) min / 60;

	printf("\nHangle %f",hangleA);
	printf("\nHangle %f",hangleB);
	printf("\nMangle %f",mangle);

	angle =  ( hangleA + hangleB - mangle ) ;
	printf("Angle is %f",angle);

}
