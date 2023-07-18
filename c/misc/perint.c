/*
Find 

gcc perint.c --std=c99

See that permutation look like total results are n!. Not sure on the math though.

The program ws dated ...  (Tue, Aug 22 2006 05:45:06 AM)


Integet set's permutations...
 How many elements...... atmost 10 supported as of static array5


 Enter elemets 1
2
3
4
5

Per#      1  1  2  3  4  5
Per#      2  1  2  3  5  4
Per#      3  1  2  4  3  5
Per#      4  1  2  4  5  3
Per#      5  1  2  5  4  3
Per#      6  1  2  5  3  4
Per#      7  1  3  2  4  5
Per#      8  1  3  2  5  4
Per#      9  1  3  4  2  5
Per#     10  1  3  4  5  2
Per#     11  1  3  5  4  2
Per#     12  1  3  5  2  4
Per#     13  1  4  3  2  5
Per#     14  1  4  3  5  2
Per#     15  1  4  2  3  5
Per#     16  1  4  2  5  3
Per#     17  1  4  5  2  3
Per#     18  1  4  5  3  2
Per#     19  1  5  3  4  2
Per#     20  1  5  3  2  4
Per#     21  1  5  4  3  2
Per#     22  1  5  4  2  3
Per#     23  1  5  2  4  3
Per#     24  1  5  2  3  4
Per#     25  2  1  3  4  5
Per#     26  2  1  3  5  4
Per#     27  2  1  4  3  5
Per#     28  2  1  4  5  3
Per#     29  2  1  5  4  3
Per#     30  2  1  5  3  4
Per#     31  2  3  1  4  5
Per#     32  2  3  1  5  4
Per#     33  2  3  4  1  5
Per#     34  2  3  4  5  1
Per#     35  2  3  5  4  1
Per#     36  2  3  5  1  4
Per#     37  2  4  3  1  5
Per#     38  2  4  3  5  1
Per#     39  2  4  1  3  5
Per#     40  2  4  1  5  3
Per#     41  2  4  5  1  3
Per#     42  2  4  5  3  1
Per#     43  2  5  3  4  1
Per#     44  2  5  3  1  4
Per#     45  2  5  4  3  1
Per#     46  2  5  4  1  3
Per#     47  2  5  1  4  3
Per#     48  2  5  1  3  4
Per#     49  3  2  1  4  5
Per#     50  3  2  1  5  4
Per#     51  3  2  4  1  5
Per#     52  3  2  4  5  1
Per#     53  3  2  5  4  1
Per#     54  3  2  5  1  4
Per#     55  3  1  2  4  5
Per#     56  3  1  2  5  4
Per#     57  3  1  4  2  5
Per#     58  3  1  4  5  2
Per#     59  3  1  5  4  2
Per#     60  3  1  5  2  4
Per#     61  3  4  1  2  5
Per#     62  3  4  1  5  2
Per#     63  3  4  2  1  5
Per#     64  3  4  2  5  1
Per#     65  3  4  5  2  1
Per#     66  3  4  5  1  2
Per#     67  3  5  1  4  2
Per#     68  3  5  1  2  4
Per#     69  3  5  4  1  2
Per#     70  3  5  4  2  1
Per#     71  3  5  2  4  1
Per#     72  3  5  2  1  4
Per#     73  4  2  3  1  5
Per#     74  4  2  3  5  1
Per#     75  4  2  1  3  5
Per#     76  4  2  1  5  3
Per#     77  4  2  5  1  3
Per#     78  4  2  5  3  1
Per#     79  4  3  2  1  5
Per#     80  4  3  2  5  1
Per#     81  4  3  1  2  5
Per#     82  4  3  1  5  2
Per#     83  4  3  5  1  2
Per#     84  4  3  5  2  1
Per#     85  4  1  3  2  5
Per#     86  4  1  3  5  2
Per#     87  4  1  2  3  5
Per#     88  4  1  2  5  3
Per#     89  4  1  5  2  3
Per#     90  4  1  5  3  2
Per#     91  4  5  3  1  2
Per#     92  4  5  3  2  1
Per#     93  4  5  1  3  2
Per#     94  4  5  1  2  3
Per#     95  4  5  2  1  3
Per#     96  4  5  2  3  1
Per#     97  5  2  3  4  1
Per#     98  5  2  3  1  4
Per#     99  5  2  4  3  1
Per#    100  5  2  4  1  3
Per#    101  5  2  1  4  3
Per#    102  5  2  1  3  4
Per#    103  5  3  2  4  1
Per#    104  5  3  2  1  4
Per#    105  5  3  4  2  1
Per#    106  5  3  4  1  2
Per#    107  5  3  1  4  2
Per#    108  5  3  1  2  4
Per#    109  5  4  3  2  1
Per#    110  5  4  3  1  2
Per#    111  5  4  2  3  1
Per#    112  5  4  2  1  3
Per#    113  5  4  1  2  3
Per#    114  5  4  1  3  2
Per#    115  5  1  3  4  2
Per#    116  5  1  3  2  4
Per#    117  5  1  4  3  2
Per#    118  5  1  4  2  3
Per#    119  5  1  2  4  3
Per#    120  5  1  2  3  4 

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct data
{
 int array[MAX];
 int st;//starts from 0
 int ntimes;
 int size;
};

void display(struct data *d,unsigned int nofp)
{
	printf("\nPer#%7d ",nofp);

	for(int i=0;i<d->size;i++)
		printf("%2d ",d->array[i]);

}
void permutation(struct data d)
{
	static unsigned int np=0;
	if(d.ntimes==1)
	{
		np++;
		display(&d,np);
	}
	else
	{
		struct data tempd;

		for(int count=0;count<d.ntimes;count++)
		{
			int t;
			tempd = d;
			t = tempd.array[tempd.st];
			tempd.array[tempd.st] = tempd.array[tempd.st+count];
			tempd.array[tempd.st+count]=t;

			tempd.st++;
			tempd.ntimes--;

			permutation(tempd);
		}
	}
}
void main()
{
 struct data d;
 int s;//size
 printf("\n Integet set's permutations... ");
 printf("\n How many elements...... atmost 10 supported as of static array");
 scanf("%d",&s);

 printf("\n");
 if(s>10)
 {
	printf("\n Max 10 elements supported ... try again for less.");
	exit(0);
 }
 printf("\n Enter elemets ");
 for(int i=0;i<s;i++)
    scanf("%d",&d.array[i]);

 d.st =0;
 d.ntimes= s;
 d.size=s;

 permutation(d);

}
