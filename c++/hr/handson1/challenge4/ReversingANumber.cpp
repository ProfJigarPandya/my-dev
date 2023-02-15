#include <iostream>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int idata;
    int remainder;
    
    int rhszeroflag=true;//assume that its zero from right hand side and not to be printed
    
    cin>>idata;
    
    if(idata<=0)
        return -1;
    
    while(idata)
    {
        remainder=idata%10;
        if(remainder)
           rhszeroflag=false; 
        if(remainder || !rhszeroflag)
                cout<<remainder;
        
        idata=idata/10;
    }
    return 0;
}
