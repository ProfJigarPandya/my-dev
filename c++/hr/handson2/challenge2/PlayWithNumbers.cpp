#include <iostream>

int& find_smaller(int &n1, int &n2)
{
    if(n1<n2)
        return n1;
    else
        return n2;
}

int main() {
  	
  	int num1, num2;
	std::cin >> num1 >> num2;
  	
  	find_smaller(num1, num2) *= 2;
  	
  	if(num1 > num2)
      	std::cout << num1;
  	else
      	std::cout << num2;
  
    return 0;
}
