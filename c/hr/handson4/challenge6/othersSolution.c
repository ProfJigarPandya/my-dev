#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned long long int n, a, c = 1, i = 0, d;
    int rem;
    scanf("%llu", &n);
    if (n == 0)
    {
        printf("0\n0\n0");
        exit(0);
    }
    a = n;
    while (a != 0)
    {
        rem = a % 2;
        c = c * 10 + rem;
        a /= 2;
        i++;
    }
    for (; i > 0; i--)
    {
        printf("%d", c % 10);
        c /= 10;
    }
    printf("\n");
    a = n;
    while (a != 0)
    {
        rem = a % 8;
        c = c * 10 + rem;
        a /= 8;
        i++;
    }
    for (; i > 0; i--)
    {
        printf("%d", c % 10);
        c /= 10;
    }
    printf("\n");
    a = n;
    c = 1;
    while (a != 0)
    {
        rem = a % 16;
        c = c * 100 + rem;
        a /= 16;
        i++;
    }
    for (; i > 0; i--)
    {
        if ((c % 100) < 10)
            printf("%d", c % 100);
        else
            printf("%c", (55 + (c % 100)));
        c /= 100;
    }
    //printf("\n");
    return 0;
}

