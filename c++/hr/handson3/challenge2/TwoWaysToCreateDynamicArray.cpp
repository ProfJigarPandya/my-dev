#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
      int i, j, m, n;
    
      cin>>m>>n;

//    one method
    int **ip2;
    ip2 = (int **) malloc(sizeof(int *) * m);
    for(i = 0; i < m; i++)
    {
        ip2[i] = (int *) malloc(sizeof(int) * n);
    }
    
//    another method
//    int (*ip2)[n];
//    ip2 = (int (*)[n]) malloc(sizeof(int) * m * n);
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> *(*(ip2 + i) + j);
        }
    }
    for(i = 0; i < (m-1); i++)
    {
        for(j = 0; j < (n-1); j++)
        {
            cout<<*(*(ip2 + i) + j)<<"\t";
        }
        cout<<*(*(ip2 + i) + j);
        cout<<endl;
    }
    for(j = 0; j < (n-1); j++)
    {
        cout<<*(*(ip2 + i) + j)<<"\t";
    }
    cout<<*(*(ip2 + i) + j);
    
    for(i = 0; i < m; i++)
    {
        free(ip2[i]);        
    }
    free(ip2);  
}
