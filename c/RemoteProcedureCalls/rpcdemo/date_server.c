/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "date.h"
#include <time.h>
long *
bin_date_1_svc(struct svc_req *rqstp)
{
	static long  result;

	/*
	 * insert server code here
	 */
	result = time( (long *)0 );

	return &result;
}

char **
str_date_1_svc(long arg1,  struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */
	result = ctime( &arg1 );

	return &result;
}
