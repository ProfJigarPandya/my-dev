#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_largest_number(int number_1, int number_2, int number_3, int number_4)
{
  	/* Remove this comment and write your code here */
	int largest=number_1;
	if(number_2>largest)
		largest=number_2;
	if(number_3>largest)
		largest=number_3;
	if(number_4>largest)
		largest=number_4;

	
	return largest;
}

int main() {

    int number_1, number_2, number_3, number_4;
  	scanf("%d %d %d %d", &number_1, &number_2, &number_3, &number_4);
  	printf("%d", find_largest_number(number_1, number_2, number_3, number_4));
    return 0;
}
