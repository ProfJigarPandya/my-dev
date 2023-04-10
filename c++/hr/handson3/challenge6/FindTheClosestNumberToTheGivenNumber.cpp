using namespace std;

#include <vector>
#include <iostream>
#include <iterator> //for std::istream_iterator



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int input;
    cin>>n;
    vector<int> sortedLookupVector;

    for(int i=0;i<n;i++)
    {
        cin>>input;
        sortedLookupVector.push_back(input);
    }

    while(1)
    {
        cin>>input;
        if(cin.eof())
        {
            break;
        }
        //look out input number from sortedLookupVector
        int low=0, high=sortedLookupVector.size()-1;
        int mid;

        if(input<=sortedLookupVector.at(0))//Smaller than the first
        {
            cout<<sortedLookupVector.at(0)<<" ";
        }
        else if(input>=sortedLookupVector.at(sortedLookupVector.size()-1))//Bigger than the last
        {
            cout<<sortedLookupVector.at(sortedLookupVector.size()-1)<<" ";
        }
        else//In between then use binary search logic
        {
            while(low<=high)
            {
                mid=(low+high)/2;

                if(input==sortedLookupVector[mid])//At middle and found the input itself
                {
                    cout<<input<<" ";
                    break;
                }
                else if(input<sortedLookupVector[mid])//Towards the left subarray
                {
                    high=mid-1;
                }
                else//Towards the right subarray
                {
                    low=mid+1;
                }
            }

            //When the loop stops, ideally element is not present. Hence, now look the nearest logically.
            if(high<low)
            {
                int lowdiff, highdiff;
                lowdiff = sortedLookupVector[low]-input;
                if(lowdiff<0)
                	lowdiff=lowdiff*(-1);

                highdiff = sortedLookupVector[high]-input;
                if(highdiff<0)
                	highdiff=highdiff*(-1);

                //When two numbers in the given list are at the same distance from the given number then choose the smaller number as an answer.
                if(lowdiff==highdiff)
                {
                	if(sortedLookupVector[low]<sortedLookupVector[high])
                	{
                    	cout<<sortedLookupVector[low]<<" ";//choose the smaller
                	}
                	else
                	{
                		cout<<sortedLookupVector[high]<<" ";
                	}
                }
                else if (lowdiff<highdiff)
                {
                    cout<<sortedLookupVector[low]<<" ";//nearest is element located at low position
                }
                else
                {
                    cout<<sortedLookupVector[high]<<" ";//nearest is element located at high position
                }
            }
        }
    }

    return 0;
}
