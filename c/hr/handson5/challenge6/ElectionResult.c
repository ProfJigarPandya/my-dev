/*Election is contested by n candidates.
Candidates are numbered from 1 to n.
Voter can give vote to a candidate by his/her number.
Any number between 1 to n from voter is considered vote to particular candidate, and 0 from voter is considered NOTA (Non Of The
Above).
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int n;//number of candidates
	scanf("%d",&n);
	long int votes[n+1]={0};//0-for NOTA, 1-candidate1, n candidate n totaling n candidates.

	int i,m,candidate;//total number of votes
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&candidate);
		votes[candidate]++;
	}

	
	int maxvalue=votes[0];
	int maxlocation=0;
	int maxcount=1;

	for(i=1;i<=n;i++) //note that array size is n+1
	{
		if(votes[i]>maxvalue) //new maximum found
		{
			maxvalue=votes[i];
			maxlocation=i;
			maxcount=1;
		}
		else if (votes[i]==maxvalue)
		{
			maxcount++;
		}
		else
		{
			//do nothing. continue the loop for next.
		}
	}

	// winning candidate’s number, in case of clear victory by any candidate
	// 0, if NOTA wins.
	// -1, if there is a tie.
	if(maxcount>1)
	{
		printf("-1");//tie
	}
	else if((maxcount==1) && (maxlocation==0))
	{
		printf("0");//NOTA
	}
	else
	{
		printf("%d",maxlocation);
	}
    return 0;
}

