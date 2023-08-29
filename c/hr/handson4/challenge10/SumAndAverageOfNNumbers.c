/* Sum and Average of 'n' numbers
 *
 * */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n;
	int inputNumber;
	int sum=0;
	scanf("%d",&n);
	int times=n;
	while(times)
	{
		scanf("%d",&inputNumber);
		sum+=inputNumber;
		times--;
	}
	printf("%d\n",sum);
	printf("%.2f\n",sum/(float)n);


	
    return 0;
}

