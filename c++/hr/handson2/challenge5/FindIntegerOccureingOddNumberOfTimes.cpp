#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numberOfInputs;
    int input;
    int i,j;
    bool isErased=false;
    vector<int> recordOdds;
    
    cin>>numberOfInputs;
    for(i=0;i<numberOfInputs;i++)
    {
        cin>>input;
        int size = recordOdds.size();
        for(j=0;j<size;j++)
        {
			
            if(recordOdds[j]==input)
            {
		//cout<<"At"<<recordOdds.at(j);
                recordOdds.erase(recordOdds.begin()+j);
		//cout<<"repeat:"<<recordOdds[j]<<endl;
                isErased=true;
                break;
            }
        }
        if(isErased==false)
        {
            recordOdds.push_back(input);
        }      
        else
            isErased=false; //next turn reset
    }
 
    cout<<recordOdds.at(0);
    
    return 0;
}

