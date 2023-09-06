#include <stdio.h>
//PUMAS REBL TAC
int main()
{
	printf("%d\n",8-3||(8-3*2)+3&&2-11%3);//P,M
	printf("%d\n",8-3||(8-6)+3&&2-11%3);//P,A
	printf("%d\n",8-3||2+3&&2-11%3);//M
	printf("%d\n",8-3||2+3&&2-2);//A
	printf("%d\n",5||2+3&&2-2);//A
	printf("%d\n",5||5&&2-2);//A
	printf("%d\n",5||5&&0);//L && has higher than L ||
	printf("%d\n",5||0);//L
	printf("%d\n",1);
	printf("%d\n",8-3||(8-3*2)+3&&2-11%3);

}
