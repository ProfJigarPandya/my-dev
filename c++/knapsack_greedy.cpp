//Knapsack solution using greedy approach.
using namespace std;

#include <iostream>
#define OBJS 10

void sort(float arr[][4], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-(i+1);j++)
		{
		       if( arr[j][3] < arr[j+1][3])
		       {
			  float tarr[1][4];
			  tarr[0][0] = arr[j][0];
			  tarr[0][1] = arr[j][1];
			  tarr[0][2] = arr[j][2];
			  tarr[0][3] = arr[j][3];

			  arr[j][0] = arr[j+1][0];
			  arr[j][1] = arr[j+1][1];
			  arr[j][2] = arr[j+1][2];
			  arr[j][3] = arr[j+1][3];


			  arr[j+1][0] = tarr[0][0];
			  arr[j+1][1] = tarr[0][1];
			  arr[j+1][2] = tarr[0][2];
			  arr[j+1][3] = tarr[0][3];
		       }
		}
	}
}
void dispdata(float arr[][4], int n)
{
	cout<<"\value   weight   status   ratio ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"  "<<arr[i][3];
	}
}
int main()
{
 float iobjects[OBJS][4];
 int n;
 int capacity;

 cout<<"\n Enter how many distinct objects available";
 cin>>n;
 if(n>OBJS) { cout<<"\n Sorry, static array allocation size is "<<OBJS<<" only"; return 0; }
 if(n==0) { cout <<"no objects than need not to apply algo."; return 0;}

 for(int i=0;i<n;i++)
 {
	cout<<"\n Enter for "<<i<<" th objects";
	cout<<"\n Enter value ";
	cin>>iobjects[i][0];
	cout<<"\n Enter Weight";
	cin>>iobjects[i][1];
	iobjects[i][2]=0.0;
	iobjects[i][3] = iobjects[i][0]/iobjects[i][1];
 }

 cout<<"\n Enter capacity of Main Bucket ";
 cin>>capacity;


 sort(iobjects,n);

 float stweight=0;
 int index=0;
 while(stweight < (float) capacity)
 {
    if( iobjects[index][1] < (capacity - stweight) && ( iobjects[index][2] == 0.0))
    {
	iobjects[index][2] = 1.0;
	stweight+=iobjects[index][1];
    }
    else if(iobjects[index][2] == 0.0)
    {
       iobjects[index][2] = (  (capacity - stweight)  / ( iobjects[index][1] ) );
       stweight = capacity;
    }
    else
       cout<<"\n End of objects ";

   index++;

   if(index ==n)
   {
	   cout<<"\n Capacity of tank is too much... All the objects fully accomodated";
	   break;
   }

 }


 dispdata(iobjects,n);


 return 0;
}

/*
 Enter how many distinct objects available5

 Enter for 0 th objects
 Enter value 40

 Enter Weight20

 Enter for 1 th objects
 Enter value 50

 Enter Weight60

 Enter for 2 th objects
 Enter value 30

 Enter Weight80

 Enter for 3 th objects
 Enter value 40

 Enter Weight10

 Enter for 4 th objects
 Enter value 30

 Enter Weight20

 Enter capacity of Main Bucket 100

alue   weight   status   ratio
40 10 1  4
40 20 1  2
30 20 1  1.5
50 60 0.833333  0.833333
30 80 0  0.375
*/
