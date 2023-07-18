#include <stdio.h>
struct { int x:1; int y:2; int z:4; } s1; 
       struct { int x:4; int y:2; int z:1; } s2;
       int main(){
              s1=s2;
       }

