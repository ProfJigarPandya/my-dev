//============================================================================
// Name        : NLogNTimeCompDemo.cpp
// Author      : ProfJigarPandya
// Description : Explain what an O(NLogN) algorithm might be running internally.
// Source : https://onlinecourses.nptel.ac.in/noc23_cs103/unit?unit=17&assessment=239
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int myfunction(int n)
{
	int cost=0;
	int ext,inn;
	for(ext=0;ext<n;ext++)
	{
		for(inn=1;inn<n;inn*=2)
		{
			cost+=1;
		}
	}
	return cost;
}

int main() {
	cout << "!!!Hello World!!! Here, I am explaining what an NLogN algorithm might be running internally." << endl; // prints !!!Hello World!!!
	int max,n;
	//int dummy;

	cout<<"\nEnter max";
	cin>>max;

	int cost;

for(n=1;n<=max;n++)
	{
		cost = myfunction(n);
		if(n*log2(n)==cost)
			cout<<setw(5)<<n<<setw(10)<<myfunction(n)<<setw(20)<<n*log2(n)<<endl;
	}
	//cin>>dummy;

	return 0;
}
