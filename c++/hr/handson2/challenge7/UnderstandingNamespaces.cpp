#include<iostream>

int x;
    
namespace nspace
{
        int x;
        int y;
}

int main()
{
        //int y;
        std::cin >> nspace::x >> nspace::y;
        using namespace nspace;
        using nspace::x;
        using nspace::y;
        std::cout << x << " " << y;
        return 0;
}
