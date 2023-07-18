#include <stdio.h>
#define TEST 123
//#ifdef (TEST)
#ifdef TEST
#undef TEST
#endif
#define TEST 123
int main()
{
	printf("\n Testing macro %d", TEST);

}
