/* selection sort */
using namespace std;

#include <iostream>

#define MAX 10

int main()
{
 int array[MAX];
 int n, i, j, index, temp, max;

 cout<<"\n How many elements to be sorted ";
 cin>>n;
 if(n>MAX)
 {
	cout<<"\n Sorry, not enough space:";
	return 0;
 }
 for(i=0;i<n;i++)
 {
  cin>>array[i];
 }

 for(i=n-1;i>=0;i--)
 {
   max = array[0];
   index = 0;
   for(int j=0;j<=i;j++)
   {
    if(array[j]>max)
    {
	max = array[j];
	index = j;
    }
   }
   temp =array[i];
   array[i] = array[index];
   array[index] = temp;
  }

  cout<<"\n Data sorted in ascending order ";
  for(i=0;i<n;i++)
    cout<<"\n"<<array[i];

  return 0;
}
