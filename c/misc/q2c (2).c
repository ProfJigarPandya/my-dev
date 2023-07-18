#include <stdio.h>
enum boolean {false, true};

int main()
{
 //int data[]={1,3,33,2,7,4,5};
 //int data[]={1,1,33,2,7,4,5};
 //int data[]={1,3,33,2,7,4,1};
 //int data[]={1,3,33,2,7,1,5};
 //int data[]={1,3,33,2,7,4,3};
 //int data[]={1,3,33,3,7,4,3};
 //int data[]={1,1,1,1,1,1,1};
 int data[]={1,2,3,4,5,6,7};
 
 int n=sizeof(data)/sizeof(int);
 
 int i,j;
 enum boolean flag=false; //not found duplicate
 
 printf("\n N elements %d", n);
 i=0;
 while(i<n)
 {    
        j=i+1;
 	while(j<n)
	{
		if(data[i]==data[j])
		{
			flag=true;
			break;
		}
		j++;
	}

	if(flag)
		break;
	i++;
 }

 if(flag)
	printf("\n List has first duplicate at location %d %d value %d",i+1,j+1,data[i]);
 else
	printf("\n List has no duplicates ");	
}
