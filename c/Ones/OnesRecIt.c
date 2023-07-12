/*
 Here, it is important to observe the running time based on number of 1's generated. See towards the end of this program to learn more.
Edit and run using 
gcc OnesRecIt.c -lm
Edit and run using 
gcc OnesRecIt.c -lm
./a.out | wc -c

*/
#include <stdio.h>
#include <math.h>

void Ones(int n)
{
	if(n==0)
		printf("1");
	else
	{
		int i;
		for(i=1;i<=pow(2,n);i++)
			Ones(n-1);
	}
}

int main()
{
	int n=0;
	//int n=1;
	//int n=2;
	//int n=3;
	//int n=4;
	//int n=5;
	//int n=6;
	//int n=7;
	//int n=8;
	Ones(n);
	return (0);	
}

//Analysis
// n=0, 1 
// n=1, 2^1 times 1  => 2 => 2^1
// n=2, 2^2 times 2 => 8 => 2^3 => 2^(2+1)
// n=3, 2^3 times 8 => 64 => 2^6 => 2^(3+3) => 2^(3+2+1)
// n=4, 2^4 times 64 => 1024 => (2^10) => 2^(4+6) => 2^(4+3+3)=> 2^(4+3+2+1)
// n=5, 2^5 times 1024 => 32769 => 2^15 => 2^(5+10) => 2^(5+4+6) => 2^(5+4+3+3) => 2^(5+4+3+2+1) 
// n=6, 2^6 times 32769 => 2097152 => 2^21
// n=7, 2^7 times 2097152 => 268435456 => 2^28
// n=8, 2^8 times 268435456 => 2^8 times 2^28 => 2^(8+28) = 2^(36) => 68719476736 (p.s. Took ~20 minutes to finish with wc -c)
//...
//n, 2^(i=1 to n Sigma(i)) => 2^(n(n+1)/2)
// 2 to the power of n(n+1)/2
