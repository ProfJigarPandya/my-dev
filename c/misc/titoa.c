#include <stdio.h>
#include <stdlib.h>

/*
[jpandya@JMP programs]$ man 3 itoa
No entry for itoa in section 3 of the manual


[jpandya@JMP programs]$ man 3 atoi

NAME
       atoi, atol, atoll, atoq - convert a string to an integer

SYNOPSIS
       #include <stdlib.h>

       int atoi(const char *nptr);
       long atol(const char *nptr);
       long long atoll(const char *nptr);
       long long atoq(const char *nptr);
*/

int main()
{
  char str[20]="12345";
  int data;
  data=atoi(str);
  data=str;
  printf("data is %d",data);
  //printf("15 in binary is %s",itoa(15,str,2));
}
