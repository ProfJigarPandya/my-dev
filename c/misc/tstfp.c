#include <stdio.h>

int f1();
int f2();
int f3();
int f4();
int (*pf4)();
int kt(int (*fn)(void));

int main()
{

 kt(f2);


 kt(f1);


 kt(f2);


 kt(f3);


 pf4=&f4;
 kt(*pf4);


}
int kt(int (*fn)(void))
{
 int r;
 r=(*fn)(); 
}
int f1()
{
 printf("I am f1");
 return 1;
}
int f2()
{
 printf("I am f2");
 return 2;
}
int f3()
{
 printf("I am f3");
 return 3;
}

int f4()
{
 printf("I am pf4");
 return 4;
}
