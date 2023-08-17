//A cyclist travels at 'x' km/hr (may not a whole number) for 'p' hours and then at 'y' km/hr (may not a whole number) for 'q' hours. Find his average speed.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	float speedX;
	int hoursP;
	float speedY;
	int hoursQ;
	scanf("%f",&speedX);
	scanf("%d",&hoursP);
	scanf("%f",&speedY);
	scanf("%d",&hoursQ);
	//Output can contain average speed upto 6 decimal places.
	printf("%0.6f",((speedX*hoursP)+(speedY*hoursQ))/(hoursP+hoursQ));

    return 0;
}

