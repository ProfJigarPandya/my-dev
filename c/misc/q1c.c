//Two D array dynamically. Test.
#include <stdio.h>
#include <stdlib.h>
#define NROWS 3
#define NCOLS 3
int main()
{
	//approach 1
	int i,j;

	int **array1 = (int **) malloc(NROWS*sizeof(int *));


	int a2d[NROWS][NCOLS] = {1,2,3,4,5,6,7,8,9};
	if(array1==NULL)
	{
		printf("\n Error in memory allocation for array1");
		exit(1);
	}
	for(i=0;i<NROWS;i++)
	{
		array1[i]=(int *) malloc (NCOLS *sizeof(int));
	
		if(array1[i]==NULL)
		{
			printf("\n Error in memory allocation for array1 cols");
			exit(1);
		}
		for(j=0;j<NCOLS;j++)
		{
			array1[i][j] = a2d[i][j];
		}
	}

	printf ("\n");
	for(i=0;i<NROWS;i++)
	{
		for(j=0;j<NCOLS;j++)
		{
			printf("\t%d", array1[i][j]);
		}
		printf("\n");
	}


	//Approach 2  -- Exam Given way, if we want to really use it with syntax of 2darray a[i][j], is incorrect.See the corrected way as below. 
	//int *array2;
	//array2 = (int *) malloc (NROWS*NCOLS*sizeof(int));
	
//	[jigar.pandya@localhost sess3]$ gcc q1c.c 
//q1c.c: In function ‘main’:
//q1c.c:61:13: error: subscripted value is neither array nor pointer nor vector
//    array2[i][j]=a2d[i][j];
//           ^
//q1c.c:62:28: error: subscripted value is neither array nor pointer nor vector
//    printf("\t%d", array2[i][j]);
//                          ^

	
	//UnComment above two lines and uncomment below for it to see error. 
	//Instead of pointer to an integer a 2d array name has to be pointer to a row containing cols number of elements.
	
	int (*array2)[NCOLS];
	array2 = (int (*)[NCOLS]) malloc (NROWS*NCOLS*sizeof(int));
	
	if(array2==NULL)
	{
		printf("\n Error in memory allocation for array2");
		exit(1);
	}

	printf ("\n");
	for(i=0;i<NROWS;i++)
	{
		for(j=0;j<NCOLS;j++)
		{
			array2[i][j]=a2d[i][j];
			printf("\t%d", array2[i][j]);
		}
		printf("\n");
	}

	//Approach1 free/release dynamically allocated memory afte usage as below:
	
	for(i=0;i<NROWS;i++)
		free(array2[i]); //seperately deallocate memmory for all rows
	
	free(array2); //deallocate array of pointer.



	//Approach 2 - correct way and simpler for 2darray
	int (*rowptr)[NCOLS];
	rowptr = (int (*)[NCOLS]) malloc (NROWS*NCOLS*sizeof(int));
	
	if(rowptr==NULL)
	{
		printf("\n Error in memory allocation for array2");
		exit(1);
	}

	printf ("\n");
	for(i=0;i<NROWS;i++)
	{
		for(j=0;j<NCOLS;j++)
		{
			rowptr[i][j]=a2d[i][j];
			printf("\t%d", rowptr[i][j]);
		}
		printf("\n");
	}
	return(0);

	
	
	//Approach2 free/release dynamically allocated memory after usage as below:
	free(rowptr); //All the bytes allocated by corresponding malloc will be released.

	//Approach 1 vs Approach 2;
	// Approach 1 has rows distributed across memory. Also, extra memory is occupied by array of pointers to rows. Approch1 is suitable if the row may contain different number of elements i.e. ragged array. Approach2 is suitable for having used contiguous memery location. Freeing memory is also different logically.
	
	
	
}
