#include <stdio.h>
#include <stdlib.h>
int main()
{     
         srand(time(0));
         printf("random number is %ld",random()%7);
         return 0;
}
