#include <iostream>

std::ostream& append_ly(std::ostream & lout)
{
    lout<<"ly";
    return lout;
}

int main() {
    
  	int n, i;
  	char word[100];
  
  	std::cin >> n;
  
    for(i = 0; i <(n-1); i++)
    {
      	std::cin >> word;
      	std::cout << word << append_ly << " ";
    }
    std::cin >> word;
    std::cout << word << append_ly;
  
    return 0;
}
