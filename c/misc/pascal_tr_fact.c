#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("clear");

    int i, n, c;

    printf("How many rows you want to show in pascal triangle?\n");
    scanf("%d",&n);

    if(n<1)
    {
	printf("Pascal trianle has not defined any behaviour for n less than 1.");
	return EXIT_FAILURE;
    }

    for ( i = 0 ; i < n ; i++ )
    {
	
        //for ( c = 0 ; c <= ( n - i - 2 ) ; c++ )
        //    printf(" "); 
        for( c = 0 ; c <= i ; c++ )
	{
            
		int counter;
		long double factofi=1, factofc=1, factofi_c=1;
		
    		for( counter = 1 ; counter <= i ; counter++ )
		        factofi = factofi*counter;
		
    		for( counter = 1 ; counter <= c ; counter++ )
		        factofc = factofc*counter;
		
		int i_c = i-c;	
	
    		for( counter = 1 ; counter <= i_c ; counter++ )
		        factofi_c = factofi_c*counter;

		printf("%7.0LF ",factofi/(factofc*factofi_c)); 
	
	}
        printf("\n"); 
    }

    return EXIT_SUCCESS;

}
