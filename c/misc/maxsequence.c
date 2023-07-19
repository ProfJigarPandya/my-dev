/*
INCOMPLETE
You are given an array of integers (both positive and negative), Find the continuous
sequence with the largest sum. Return the sum.
EXAMPLE
Input: {2, -8, 3, -2, 4, -10}
Output: 5 (i e , {3, -2, 4} )*/
#include <stdio.h>

int findmaxseqsum(int data[], int low,int high);
int main()
{
//int data[]={2, -8, 3, -2, 4, -10};//5
// int data[]={-2, -3, 4, -1, -2, 1, 5, -3};//7
//int data[]={-1 , -2 , 3 , 5 , 6 , -2 , -1 , 4 , -4 , 2 , -1};//15
//int data[]={-1,-2,-3,-4,-5};//-1
//int data[]={1,2,3,4,5};//15
int data[]={-1,-1,-1,2,-1,2,-1,-1,-1};
//int data[]={+7,-6,-8,+5,-2,-6,+7,+4,+8,-9,-3,+2,+6,-4,-6};//19

 int n=sizeof(data)/sizeof(int);
 int result;
 result=findmaxseqsum(data,0,n-1);
 printf("\n Result is %d ",result);
 return 0;
}


int findmaxseqsum(int data[], int low, int high)
{
  static int counter=0;
  int i, total, l1h, lh1, lh, max; 
  int arr[4];

  if(low>=high)
	return data[low];
  else
  {
	total = 0;
	for(i=low;i<=high;i++)
	{
		total += data[i];
	}
	max=arr[0]=total;
	arr[1] = findmaxseqsum(data,low+1,high);
	arr[2] =  findmaxseqsum(data,low+1,high-1);
	arr[3] = findmaxseqsum(data,low,high-1);

	printf("\n %d Message a  %d b  %d c %d  d %d",++counter, arr[0],arr[1],arr[2],arr[3]);

	for(i=1;i<4;i++)
	{
	
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
  }
}
