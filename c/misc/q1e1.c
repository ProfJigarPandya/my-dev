#include <stdio.h>
void main()
{
	FILE *fp1, *fp2;
	fp1 = fopen("f1.txt","w");
	fp2 = fopen("f1.txt","w");
	fprintf(fp1, "%s", "Hello");
	fprintf(fp2, "%s", "DDU");
	fclose(fp1);
	fclose(fp2);
}
