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
    int answer=0;
    int i;
    cin>>numberOfInputs;
    for(i=0;i<numberOfInputs;i++)
    {
        cin>>input;
        answer=answer^input;
    }       
    cout<<answer;
    
    return 0;
}

