#include<stdio.h>
int main()
{
    char another[2]={'y'};
    int num;
    while ( another[0] =='y')
    {
        printf("Enter a number:\t");
        scanf("%d", &num);
        printf("Sqare of %d is : %d", num, num * num);
        printf("\nWant to enter another number? y/n");
        scanf("%s", another);
    }
    return 0;
}
