//Write a program to input a character and check whether the character is alphabet or not, using conditional operator.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	char inputSymbol;
	scanf("%c",&inputSymbol);
	((inputSymbol>='A'&&inputSymbol<='Z')||(inputSymbol>='a'&&inputSymbol<='z'))!=0?printf("Yes"):printf("No");
    return 0;
}

