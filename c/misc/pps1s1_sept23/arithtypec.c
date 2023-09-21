#include <stdio.h>
int main()
{
	char key1; unsigned int key2; int key3=-5; float key4=12.34; double key5;
	printf("char %lu bytes\n",sizeof(key1));
	printf("unsigned int %lu bytes\n",sizeof(key2));
	printf("int %lu bytes\n",sizeof(key3));
	printf("float %lu bytes\n",sizeof(key4));
	printf("double %lu  bytes\n",sizeof(key5));
	
	key1=key2;//overflow
	key2=key3;//underflow
	key5=key4;//implicit conversion
	
	15/(float)10;//explicit conversion
	return 0;
}
