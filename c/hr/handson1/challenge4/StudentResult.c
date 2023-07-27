#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int marksSub1,marksSub2,marksSub3;
	int total;//Note, that marks assumed to be in range 0-100 and hence, int total is okey. It will not overflow.
	scanf("%d",&marksSub1);
	scanf("%d",&marksSub2);
	scanf("%d",&marksSub3);

	total=marksSub1+marksSub2+marksSub3;
	printf("%d\n",total);
	printf("%f",(total)*(100)/(300.0));//Format specifiers not used yet. To be able to have float arithemetic especiall 300.0 is written and not just 300
	

    return 0;
}

