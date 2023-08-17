//Input of 5 lowercase characters is given as input. You have to convert those in UPPERCASE in the output.
#include <stdio.h>
#include <ctype.h>
int main() {

    /* Enter your code here. */    
    char a,b,c,d,e;
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    printf("%c%c%c%c%c",toupper(a),toupper(b),toupper(c),toupper(d),toupper(e));
    return 0;
}
