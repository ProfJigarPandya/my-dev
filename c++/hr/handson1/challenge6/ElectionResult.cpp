#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nNumberOfCandidates;//candidates
    cin>>nNumberOfCandidates;
    int mNumberOfVotes;//total number of votes
    cin>>mNumberOfVotes;
    int voteCount[nNumberOfCandidates+1]={0};//one extra to record NOTA
    int vote;

    for (int i=0;i<mNumberOfVotes;i++)//Read the vote in parrallel count also. Note that there is no reason to store vote itself.
    {
        cin>>vote;
        voteCount[vote]++;
    }   
    int maxCandidatePosition=0; int maxVoteCountOccurrence=1;//Assume NOTA is highest. Known maximum.
    for(int j=1;j<=nNumberOfCandidates;j++)//Note presence of equal sign here to include last candidate too.
    {
        if(voteCount[j]>voteCount[maxCandidatePosition])
        {
            maxCandidatePosition=j;
            maxVoteCountOccurrence=1;
        }
        else if (voteCount[j]==voteCount[maxCandidatePosition])
        {
            maxVoteCountOccurrence++;
        }
    }    
    if(maxVoteCountOccurrence==1)
    {
        cout<<maxCandidatePosition;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}

