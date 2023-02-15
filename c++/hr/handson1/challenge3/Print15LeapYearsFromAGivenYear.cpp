#include <iostream>

using namespace std;

/*
Print 15 leap years from a given year.

Rules of the leap year:

If a year is divisible by 400 then its a leap year.

Or if a year is divisible by 4 and NOT divisible by 100 then its a leap year.

*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int iyear;
    int counter=15;

    bool isFirst=true;



    cin>>iyear;
    
    while(counter)
    {
        //check current year is a leap year or not
        if( ((iyear%400)==0) || (  ((iyear%4)==0) && ((iyear%100)!=0) ))
        {
	    if(isFirst)
	    {
            	cout<<iyear;
		isFirst=false;
	    }
	    else
	    {
            	cout<<" "<<iyear;
            }
            counter--;
        }
        iyear++;
    }
    
    
    return 0;
}
