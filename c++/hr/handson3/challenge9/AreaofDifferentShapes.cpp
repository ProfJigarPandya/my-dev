#include <iostream>
#include <string>

double area(float r);
long double area(double l, double w);
long double area(double l);

int main() {
    float r;
    double l, w;
    std::string shapename;
    std::cin>>shapename;
    if(shapename=="circle")
    {
        std::cin>>r;
        std::cout<<area(r);
    }
    else if(shapename=="rectangle")
    {
        std::cin>>l>>w;
        std::cout<<area(l,w);
    }
    else if(shapename=="square")
    {
        std::cin>>l;
        std::cout<<area(l);
    }
    else
        std::cout<<"Shape not supported."<<std::endl;
    return 0;
}

double area(float r)
{
    return 3.14*(double)r*r;
}
long double area(double l, double w)
{
    return l*w;
}
long double area(double l)
{
    return (double)l*l;
}

