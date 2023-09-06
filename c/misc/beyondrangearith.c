#include <stdio.h>
/*
65535
0
0
65535
32767
-32768
-32768
32767
*/
int main()
{
	unsigned short int data1=65535;
	printf("%d\n",data1);
	printf("%hu\n",data1+1);//overflow. Note that %hu for unsigned 

	unsigned  int data2=0;
	printf("%d\n",data2);
	printf("%hu\n",data2-1);//underflow. 
	
	signed  int data3=32767;
	printf("%d\n",data3);
	printf("%d\n",data3+1);//overflow. Note that %hd for signed 

	signed  int data4=-32768;
	printf("%d\n",data4);
	printf("%d\n",data4-1);//underflow

	
}

/* man 3 printf

h      A  following  integer  conversion corresponds to a
               int or unsigned   int  argument

unsigned decimal (u)
*/
