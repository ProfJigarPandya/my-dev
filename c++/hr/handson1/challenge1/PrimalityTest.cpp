#include <iostream>
#include <cmath>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int lenrem_list;
    int data;
    bool isFirst=true;
    cin>>lenrem_list;
    while(lenrem_list)
    {
        cin>>data;

        //validate input
        if(data<=1)
        {
            lenrem_list--;
            continue;
        }

        //check for prime
        int tempd;
        int sqrtdata = sqrt(data);
        for(tempd=2;tempd<=sqrtdata;tempd++)
        {
            if((data%tempd)==0)
	    { 
		
                break;
	    }
        }
        if((tempd>sqrtdata))
	{
	    if(isFirst)
	    {
		cout<<data;
		isFirst=false;
            }
	    else
	    {
	        cout<<" "<<data;
	    }
	}


        lenrem_list--;
    }
    return 0;
}

