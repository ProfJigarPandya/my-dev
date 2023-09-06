#include<stdio.h>
#include<errno.h>
#include<string.h>
extern int errno;
int main()
{
	char choice1,choice2,choice3;
	printf("Press a character.");
	scanf("%c",&choice1);
	printf("Press b character.");
	/*if(fflush(stdin)==EOF)
	{
		perror("FFLUSH error");
		printf("%s",strerror(errno));
	}*/
	scanf(" %c",&choice2);
	printf("Press c character.");
	scanf(" %c",&choice3);
	printf("You typed %c %c %c" ,choice1,choice2,choice3);
	return(0);
}
/*

jpandya@JigarPandyaHPL:~/my-dev/c/misc$ ./a.out
Press a character.a
Press b character.Press c character.d
You typed a
 djpandya@JigarPandyaHPL:~/my-dev/c/misc$ ./a.out
Press a character.asd
Press b character.Press c character.You typed a s djpandya@JigarPandyaHPL:~/my-dev/c/misc$
*/
