#include <iostream.h>
#include <conio.h>
class array
{
 public:
 int *arr; // 4/4 lower triangular array
 int len;
 array(){}
 array(int r){ arr = new int[r]; len=r; }
 int& operator[](int row)
 {
	return arr[row];
 }
 void show()
 {
  for(int i=0;i<4;i++)
   cout<<arr[i];
 }
};
void main()
{
clrscr();
array obj(4); // 4/4 ltarray

for(int i=0;i<4;i++)
 obj[i]=i;
obj.show();





getch();
}