#include<stdio.h>
int main() 
{ 
    int a = 1;
    if(a--)
          printf("True\n");
    if(++a)
          printf("False\n");
    return 0;
}

