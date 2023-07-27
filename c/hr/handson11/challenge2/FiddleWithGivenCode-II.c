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
	char names[3][10] = {
				"Gopal",
				"Krishna",
				"Shyam"
			};

	char *names_pointers[3];
	for(i = 0; i < 3; i++)
	{
		names_pointers[i] = names[i];
	}

	change(names_pointers);
	
	for(i = 0; i < 3; i++)
	{
		printf("%s\n", names[i]);
	}
	
	printf("\nNames pointed by pointer array in following sequence\n");
	for(i = 0; i < 3; i++)
	{
		printf("%s\n", names_pointers[i]);
	}
}
