#include<stdio.h>
#include<conio.h>

void sort(int no[],int n)
{
	int i=0,j,temp,k;
	for(i=0;i<n;i++)
	{
	      for(j=0;j<i;j++)
	      {
		if(no[i]<no[j])
		{
			temp = no[i];
			no[i] = no[j];
			no[j] = temp;
		}
	      }
	}
	for(i = 0;i<n;i++)
	 printf("%d  ",no[i]);
}







void main()
{
	int no[10],n,i;
	clrscr();
	printf("Enter no of elements");
	scanf("%d",&n);
	printf("\nEnter elements");
	for( i =0; i<n; i++)
		scanf("%d",&no[i]);
	sort(no,n);
	getch();

}