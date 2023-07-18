#include <stdio.h>
#ifdef DEBUG
	#define DEBUG_PRINT(a,b) fprintf(stderr, "a is %d and b is %d ",a,b)
#else
	#define DEBUG_PRINT(a,b)
#endif

int main()
{
	int a=10, b =25;
	DEBUG_PRINT(a,b);
	
}

