//============================================================================
// Name        : PartitioningNBoxesMaximally.cpp
// Author      : ProfJigarPandya
// Version     :
// Copyright   : GNU General Public License v3.0
// Description : Hello World in C++, Ansi-style
//You begin with a stack of n boxes.
//Then you make a sequence of moves. In each move, you divide one stack of boxes into two nonempty stacks. The game ends when you have n stacks, each containing a single box. You earn points for each move; in particular, if you divide one stack of height a + b into two stacks with heights a and b, then you score ab points for that move. Your overall score is the sum of the points that you earn for each move.
//What strategy should you use to maximize your total score?
//============================================================================

#include <iostream>
using namespace std;


void partition(int n, int & cost);
int main() {

	int cost;
	int testcases;//T, the number of test cases.
	cin>>testcases;
	int n;//size of the first stack of boxes
	for(int pass=1;pass<testcases;pass++)
	{
		cin>>n;
		cost=0;
		partition(n,cost);
		cout<<cost<<endl;
	}

	cin>>n;
	cost=0;
	partition(n,cost);
	cout<<cost;

	return 0;
}
void partition(int n, int &cost)
{
	if(n==1)
	{
		return;
	}
	int lhsize, rhsize;
	lhsize=n/2+(n%2);
	rhsize=n/2;
	partition(lhsize,cost);
	partition(rhsize,cost);
	cost+=(lhsize*rhsize);
	return;
}
