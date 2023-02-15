#include <iostream>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int ntc;
   
    cin>>ntc;
    if( !((1<=ntc) && (ntc<=100)) )
        return -1;
    
    
    int key;
    cin>>key;

    if( !( (1<=key) && (key<=26)) )
        return -1;
    
    char str[1000];
    int i;
    char t;
    while(ntc)
    {
        cin>>str;
        i=0;
        while(str[i])
        {
            if('A'<=str[i] && str[i]<='Z')      
            {
                t=str[i]+key;
                if(t>'Z')
                    t='A'+(t%'Z')-1;
            }    
            else if('a'<=str[i] && str[i]<='z')      
            {
                t=str[i]+key;
                if(t>'z')
                    t='a'+(t%'z')-1;
            }              
            else if('0'<=str[i] && str[i]<='9') 
            {
                t=str[i]+(key%10);
                if(t>'9')
                    t='0'+(t%'9')-1;
            } 
            else
                return -1;
            i++;
            cout<<t;
        }
	if(ntc!=1)
	        cout<<endl;
        ntc--;
    }
    
    return 0;
}
