#include <stdio.h>
//PUMAS REBL TAC
int main()
{
	printf("%d\n",8-5+8/3==65/10-2+5%2);//M
	printf("%d\n",8-5+2==65/10-2+5%2);//M
	printf("%d\n",8-5+2==6-2+5%2);//M
	printf("%d\n",8-5+2==6-2+1);//A
	printf("%d\n",3+2==6-2+1);//A
	printf("%d\n",5==6-2+1);//A
	printf("%d\n",5==4+1);//A
	printf("%d\n",5==5);//EE
	printf("%d\n",1);
	printf("%d\n",8-5+8/3==65/10-2+5%2);
}
