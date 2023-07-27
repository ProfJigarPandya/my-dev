#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void change(char **names)
{
	char *temp = names[1];
	names[1] = names[0];
	names[0] = temp;
}

int main()
{
	int i;
	char *names[3] = {
				"Gopal",
				"Krishna",
				"Shyam"
			};

	change(names);
	for(i = 0; i < 3; i++)
	{
		printf("%s\n", names[i]);
	}
}
