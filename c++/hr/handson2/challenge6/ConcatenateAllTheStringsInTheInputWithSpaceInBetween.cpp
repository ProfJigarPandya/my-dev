#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    do
    {
        cin>>str;
        std::transform(str.begin(), str.begin()+1,str.begin(), ::toupper);
        if(cin.eof())
        {
            cout<<str;
            break;
        }
        else
            cout<<str<<" ";
    }while(1);
    
    return 0;
}
