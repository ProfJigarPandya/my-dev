#include <stdio.h>
#include <time.h>

int main ()
{
	time_t time1,time2;
	char get_input [256];
	double dif_sec;

	time1=time (NULL);
	printf ("Please enter the name of your pet: ");
	scanf("%s",get_input);

	time2=time(NULL);
	dif_sec = difftime (time2,time1);
	printf ("It took you %.2lf seconds to type the name.\n", dif_sec );

	return 0;
}
