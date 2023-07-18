#include<stdio.h>
union emp
{
	float salary;
	double allowence;
};
struct person
{
	char name[20];
	unsigned age:4;
	unsigned height:6;
	union emp x;
}p[100];
int main()
{
	printf("\nSize of char  %d",sizeof(char));
	printf("\nSize of int %d",sizeof(int));
	printf("\nSize of unsigned %d",sizeof(unsigned));
	printf("\nSize of float %d",sizeof(float));
	printf("\nSize of double %d",sizeof(double));
	
	printf("\n Bytes %d ",sizeof(p));//100 * 
}
