#include<stdio.h>

int main(){

int x=10;
int far *ptr;

ptr=&x;
printf("%d",sizeof ptr);


return 0;
}
