#include <stdio.h>
void main()
{
	int arr[]={0,1,2,
		   0,1,2,
                   0,1,2};
	printf("%d\n",arr[arr[3]+arr[1]]); //arr[0+1] => 1
	printf("%d\n",arr[arr[arr[arr[1]]]]);//arr [ arr [ arr [1] ] ==> 1
}
