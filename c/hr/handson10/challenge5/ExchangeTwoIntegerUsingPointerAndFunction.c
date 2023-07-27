#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void (int *const x, int *const y)
{
    // Write code here such that values of variable a and b in main function are
    // exchanged
}
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    exchange(&a, &b);
    printf("%d %d", a, b);
  
	return 0;
}
