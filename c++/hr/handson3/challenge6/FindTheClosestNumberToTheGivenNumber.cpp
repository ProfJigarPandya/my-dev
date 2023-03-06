#include <vector>
#include <iostream>
#include <iterator> //for std::istream_iterator
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	int input;
	cin>>n;
	vector<int> sortedLookupVector;

	for(int i=0;i<n;i++)
	{
		cin>>input;
		sortedLookupVector.push_back(input);
	}

	while(1)
	{
		cin>>input;
		if(cin.eof())
		{
			break;
		}
		//look out input number from sortedLookupVector
		int prevNumber,currNumber;

		for(i=0;i<sortedLookupVector.size();i++)
		{
			if()
		}

	}

    return 0;
}
