#include <stdio.h>

int main() 
{ 
int sum=0, num; 
scanf("%d",&num); 
 while(num != -1) 
 { 
 sum += num; 
 scanf("%d", &num); 
 } 
 printf("sum =%d \n",sum); 
 return 0; 
}
