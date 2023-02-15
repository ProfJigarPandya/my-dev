#include <iostream>

using namespace std;

void dec2bin(int d)
{
    int remainder;
    remainder=d%2;
    d=d/2;
    if(d)
        dec2bin(d);
    cout<<remainder;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int decimal;
    cin>>decimal;
    if(decimal<=0)
        return -1;
    dec2bin(decimal);
    return 0;
}
