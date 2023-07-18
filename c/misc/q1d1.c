#include <stdio.h>
union {char ch; int in;} u;
struct {char ch; int in;} s;
     int main(){ 
            u = s; 
     }

