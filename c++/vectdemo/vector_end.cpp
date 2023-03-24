// vector_end.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>
int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator v1_Iter;

   v1.push_back( 10 );
   v1.push_back( 20 );
   v1.push_back( 30 );
   v1.push_back( 40 );
   v1.push_back( 50 );
   v1.push_back( 60 );

   for ( int i=0;i<v1.size();i++ )
      cout << v1[i] << endl;
   cout<<endl<<endl;
   for ( int i=0;i<v1.size();i++ )
      cout << v1.at(i) << endl;
   cout<<endl<<endl;
   for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )
      cout << *v1_Iter << endl;
}
