#include <iostream>
long reduceitv1(long input)
{   if(input==1)
        return 0;

     
    if((input%2)==0)
    {
        return 1 + reduceitv1(input/2);
    }
    else
    {
        long minusc,plusc;
        minusc=1+reduceitv1(input-1);
        plusc=1+reduceitv1(input+1);

        if(minusc<plusc)
            return minusc;
        else
            return plusc;
    }
}
long reduceitv2(long input)
{   if(input==1)
        return 0;

     
    if((input%2)==0)
    {
        return 1 + reduceitv2(input/2);
    }
    else
    {
        if((input%4 != 3) || (input==3))
            return 1 + reduceitv2(input-1);
        else
            return 1 + reduceitv2(input+1);
    }
}

long reduceitv3(long input)
{
    int count=0;
    while(input>1)
    {
        if( (input%2) == 0)
        {
            input=input/2;
        }
        else
        {
            if(((input%4)!=3) || (input==3))
            {
                input = input -1;
            }
            else
            {
                input = input +1;
            }
        }
        count++;
    }
    return count;
}

int main() {
    long input;
    std::cin>>input;
    std::cout<<reduceitv3(input);
    return 0;
}
