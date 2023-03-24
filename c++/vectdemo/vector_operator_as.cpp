// vector_operator_as.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector<int> v1, v2, v3;
   vector<int>::iterator iter;

   v1.push_back(10);
   v1.push_back(20);
   v1.push_back(30);
   v1.push_back(40);
   v1.push_back(50);

   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   v2 = v1;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;

// move v1 into v2
   v2.clear();
   cout << "\nAfter clearing v2, v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   v2 = move(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;
   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   v3.insert(v3.begin(),100);
   v3.insert(v3.begin(),200);
   v3.insert(v3.begin(),300);
   v3.insert(v3.begin(),400);
   v3.insert(v3.begin(),500);
   v3.insert(v3.begin(),600);

   cout << endl;
   cout << "v3 = " ;
   for (iter = v3.begin(); iter != v3.end(); iter++)
      cout << *iter << " ";
   cout << endl;
	
   cout<<"Before swapping v2 and v3" ;
   cout << endl;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   cout << "v3 = " ;
   for (iter = v3.begin(); iter != v3.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   v2.swap(v3);
	
   cout<<"After swapping v2 and v3";
   cout << endl;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   cout << "v3 = " ;
   for (iter = v3.begin(); iter != v3.end(); iter++)
      cout << *iter << " ";
   cout << endl;

}
