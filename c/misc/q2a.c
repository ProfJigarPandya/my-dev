//Program to swap biggest and smallest
/*
Write a program to swap the biggest and smallest number in the array of 10 [6]
elements using function. Create three functions “FindBig()” ,“FindSmall()” and
“swap()”. “FindBig()” and “FindSmall()” these functions are used to find big and
small elements, and “swap()” will work for swapping those numbers. Pass array as
an argument to all functions.

Assumption of requirement:
If there are duplicates max or min then it swaps the first occurance of both.

*/

#include <stdio.h>
#define SIZE 10
int FindBig(int arr[],int size);
int FindSmall(int arr[],int size);
void Swap(int arr[],int size,int big, int small);
int main()
{
 int arr[SIZE]
	//={1,1,2,1,2,1,1,0,1,0};
	//={1,1,1,1,1,1,1,1,1,1};
	={0,1,2,3,4,5,6,7,8,9};
 int big, small, i;

 printf("Array before swapping biggest and smallest elements \n");
 for(i=0;i<SIZE;i++)
 {
 	printf("%d\n",arr[i]);
 }

 big=FindBig(arr,SIZE);
 small=FindSmall(arr,SIZE);
 printf("Biggest number is %d \n",big);
 printf("Smallest number is %d \n",small);
 Swap(arr,SIZE,big,small);
 
 printf("Array after swapping biggest and smallest elements \n");
 for(i=0;i<SIZE;i++)
 {
 	printf("%d\n",arr[i]);
 }
}

int FindBig(int arr[],int size)
{
 int i;

 int big,temp;

 if(size<=0)
	return 0;// Array is empty.

 big=arr[0];
 for(i=1;i<size;i++)
 {
   if(arr[i]>big)
   {
	big=arr[i];
   }
 }

 return big;
}
int FindSmall(int arr[],int size)
{
 int i;

 int small,temp;

 if(size<=0)
        return 0;// Array is empty.

 small=arr[0];
 for(i=1;i<size;i++)
 {
   if(arr[i]<small)
   {
        small=arr[i];
   }
 }

 return small;

}
void Swap(int arr[],int size,int big, int small)
{
 int posbig=-1, possmall=-1, i;

 if((size<=0) || (big==small))
	return ;

 //Find the first position of biggest and smallest number
 for(i=0;i<size;i++)
 {
	if(posbig==-1 && arr[i]==big)
		posbig=i;
	else if(possmall==-1 && arr[i]==small)
		possmall=i;
	
	if( (posbig!=-1) && (possmall!=-1))
		break;
 }

 printf("Position of biggest is %d \n",posbig);
 printf("Position of smallest is %d \n",possmall);

 //Swap the elements as per the position
 i=arr[posbig];
 arr[posbig]=arr[possmall];
 arr[possmall]=i;	
	
 return;
}
