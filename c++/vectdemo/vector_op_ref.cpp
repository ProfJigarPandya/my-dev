#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 20 );

   cout<<"Note that i is reference while j is not"<<endl;

   int& i = v1[0];
   int j = v1[1];
   cout << "The first integer of v1 is via i" << i << endl;
   cout << "The second integer of v1 is via j" << j << endl;
   
   i++;
   cout<<"\n i is "<<i<<endl;
   cout<<"Vector data "<<v1[0]<<" "<<v1[1]<<endl;
	
   j++;
   cout<<"\n j is "<<j<<endl;
   cout<<"Vector data "<<v1[0]<<" "<<v1[1]<<endl;
}
