#include <stdio.h>

typedef
struct Cmplx {
  	int real, img;
} Complex;


Complex sum(Complex cnums[], int n) {
  	/* Write your code here */
}

int main() {

    int n;
	scanf("%d", &n);
  	Complex input_numbers[n];
  	for(int i = 0; i < n; i++)
      	scanf("%d %d", &input_numbers[i].real, &input_numbers[i].img);
  	Complex result = sum(input_numbers, n);
  	printf("%d %d", result.real, result.img);
    return 0;
}
