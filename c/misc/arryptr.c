#include <stdio.h>
#define R 5
#define C 3
int main()
{
 
 /*int arr[5],i
 int *parr;
 parr=arr;
 for(i=0;i<5;i++)
	*(parr+i)=i*i;

 for(i=0;i<5;i++)
	printf("\n %d", arr[i]);
*/

int arr[R][C];
int i;
int *parr;

 parr = (int *) arr;
 for(i=0;i<(R*C);i++)
	*(parr+i) = i*i;

 for(i=0;i<(R*C);i++)
	printf("\n %d", *(parr+i));
	
 return 0;
}
