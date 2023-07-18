//A simple call back program to understand usage of function to pointer in C.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*call_back) (int, int);

void test_call_back(int a, int b)
{
    printf("In call back function, a:%d \t b:%d \n", a, b);
}
void another_call_back(int a, int b)
{
    printf("In another call back function, a:%d \t b:%d ...\n", a, b);
    printf("From another call back function, Addition of a + b is %d \n",a+b);
}

void call_callback_func(call_back back)
{
    int a = 5;
    int b = 7;
    back(a, b);
}

int main(int argc, char *argv[])
{
    int ret = 0;
    call_back back;

    back = test_call_back;
    call_callback_func(back);

    back = another_call_back;
    call_callback_func(back);

    return ret;
}


