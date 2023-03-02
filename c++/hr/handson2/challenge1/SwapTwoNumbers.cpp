#include <iostream>

///*retrn type here*/ swap(/*arguments here*/)
void swap(int & n1, int & n2)
{
  	/* Write code here */
    int temp;
    temp=n1;
    n1=n2;
    n2=temp;
}

int main() {
	int num1, num2;
  	std::cin >> num1 >> num2;
  	swap(num1, num2);
  	std::cout << num1 << " " << num2;
    return 0;
}
