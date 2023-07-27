#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct point
{
	int x, y;
}pt;

typedef struct rectangle
{
	char name[20];
	pt pt1;
	pt pt2;
}rect;

typedef struct circle
{
	char name[20];
	pt centre;
	int radius;
}cl;

typedef union shape
{
	rect r;
	cl c;
}sh;

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
