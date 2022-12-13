package in.jigar_pandya;

import java.util.ArrayList;

public class ActivitySelectionProblem {
	ArrayList<Activity> activitiesArrayList;
	ArrayList<Activity> solutionSet = new ArrayList<Activity>();
	public void applyActivitySelectionAlgo()
	{
		//Approach says lets finish activity as early as possible to make room for next.
	
		//As per general structure of greedy methodology algorithm
		int i,n,scheduledSequence;
		
		i=0;
		n=activitiesArrayList.size();
		scheduledSequence=1;
		while(i<n)
		{
			Activity nextGreedyBestSelection=null;
			nextGreedyBestSelection = selectNextGreedyBest();
			if(nextGreedyBestSelection!=null)
			{
				System.out.println("Next greedy best selection is "+nextGreedyBestSelection.toString());
				int returnVal=-1;
				if((returnVal=isFeasible(nextGreedyBestSelection,solutionSet))==0)
				{
					solutionSet.add(nextGreedyBestSelection);
					nextGreedyBestSelection.setScheduledSequence(scheduledSequence++);
					System.out.println(" marked for schedule at "+(scheduledSequence-1)+".");
					System.out.println();
				}
				else
				{
					nextGreedyBestSelection.setScheduledSequence(0);//Mark rejected
					System.out.println(" but rejected for reason code "+returnVal+".");
					System.out.println();
				}	
			}
			i++;
		}
	}
	private int isFeasible(Activity nextGreedyBestSelection, ArrayList<Activity> solutionSet) {
		// TODO Auto-generated method stub
		//If overlapping/not compatible return false else return true
		
		
		if(solutionSet.isEmpty())
			return 0;//success
		
		if(solutionSet.contains(nextGreedyBestSelection))
			return 1;//reference object itself is called upon twice by algorithmic circles, etc.

		//For next greedy best selected activity having start time in between previously scheduled activity's start and finish time reject it.
		int i=0;
		for(i=0;i<solutionSet.size();i++)
		{

			//nextGreedyBestSelection is overlapping exactly -tested
			if( (solutionSet.get(i).getStartTime() == nextGreedyBestSelection.getStartTime()) &&  (nextGreedyBestSelection.getFinishTime()==solutionSet.get(i).getFinishTime()) )
			{
				System.out.println("Non-compatible "+nextGreedyBestSelection+" with "+ solutionSet.get(i) + "reason code 2" );
				return 2;
			}
			//nextGreedyBestSelection is overlapped completely by others
			if( (nextGreedyBestSelection.getStartTime() < solutionSet.get(i).getStartTime()) &&  (solutionSet.get(i).getFinishTime()<nextGreedyBestSelection.getFinishTime()) )
			{
				System.out.println("Non-compatible "+nextGreedyBestSelection+" with "+ solutionSet.get(i) + "reason code 3" );
				return 3;
			}
		
			//nextGreedyBestSelection is overlapping from its starting (completely within is overruled by previous checks)
			if( (solutionSet.get(i).getStartTime() <= nextGreedyBestSelection.getStartTime()) &&  (nextGreedyBestSelection.getStartTime()<solutionSet.get(i).getFinishTime()) )
			{
				System.out.println("Non-compatible "+nextGreedyBestSelection+" with "+ solutionSet.get(i) + "reason code 4" );
				return 4;
			}

			//nextGreedyBestSelection is overlapping towards its finishing (completely within is overruled by previous checks)
			//You will not see this case, if selection is based on ordering of finish time. next greedy best selection will always have higher finish time than already scheduled.
			if( (solutionSet.get(i).getStartTime() < nextGreedyBestSelection.getFinishTime()) &&  (nextGreedyBestSelection.getFinishTime()<=solutionSet.get(i).getFinishTime()) )
			{
				System.out.println("Non-compatible "+nextGreedyBestSelection+" with "+ solutionSet.get(i) + "reason code 5" );
				return 5;
			}
			
			
		}
		return 0;//success
	}
	private Activity selectNextGreedyBest() {
		// TODO Auto-generated method stub
		int i=0;
		int n;
		n=activitiesArrayList.size();
		while(i<n)
		{
			if(activitiesArrayList.get(i).scheduledSequence != -1)//Skip which activities are already scheduled or which are not compatible
			{
				i++;
				continue; //If the activity is either selected or rejected, go to next available.
			}
			
			return activitiesArrayList.get(i);
		}
		return null;
	}
	public ActivitySelectionProblem() {
		super();
		// TODO Auto-generated constructor stub
		activitiesArrayList = new ArrayList<Activity>();
	}
	public void insertAllActivityDetails() {
		// TODO Auto-generated method stub
		int[][] sampleArray = {{1,1,4},{2,3,5},{3,0,6},{4,5,7},{5,3,9},{6,5,9},{7,6,10},{8,8,11},{9,8,12},{10,2,14},{11,12,16}};//ID, StartTime, FinishTime
		/*
		 * Solution
			Activity [activityID=1, startTime=1, finishTime=4]
			Activity [activityID=4, startTime=5, finishTime=7]
			Activity [activityID=8, startTime=8, finishTime=11]
			Activity [activityID=11, startTime=12, finishTime=14]
		 */
		
		//int[][] sampleArray = {{1,1,4},{2,3,5},{3,0,6},{4,5,7},{5,3,8},{6,5,9},{7,6,10},{8,8,11},{9,8,12},{10,2,13},{11,12,14}};
		//int[][] sampleArray = {{1,1,4},{111,1,4},{2,3,5},{3,0,6},{4,5,7},{5,3,8},{6,5,9},{7,6,10},{8,8,11},{9,8,12},{10,2,13},{11,12,14}};
		
		//System.out.println(sampleArray.length);
		for(int i=0;i<sampleArray.length;i++)
		{
			//System.out.println("Activity # "+sampleArray[i][0]+" : ["+sampleArray[i][1]+" , "+sampleArray[i][2]+"]");
			activitiesArrayList.add(new Activity());
			activitiesArrayList.get(i).setActivityID(sampleArray[i][0]);
			activitiesArrayList.get(i).setStartTime(sampleArray[i][1]);
			activitiesArrayList.get(i).setFinishTime(sampleArray[i][2]);
			activitiesArrayList.get(i).setScheduledSequence(-1);//neither selected nor rejected as of now.
		}
		//System.out.println("Sample initialization finished");
	}
	public void displayAllActivityDetails() {
		// TODO Auto-generated method stub
		int n;
		n=activitiesArrayList.size();
		for(int i=0;i<n;i++)
		{
			System.out.println(activitiesArrayList.get(i).toString());
		}
	}
	public void displaySchedule() {
		// TODO Auto-generated method stub
		//System.out.println("Displaying schedule, sorted based on the sequence allocated.");
		int n;
		n=activitiesArrayList.size();
		for(int i=0;i<n;i++)
		{
			System.out.println("ActivityID:StartTime:EndTime:Sequence   =>  "+activitiesArrayList.get(i).getActivityID()+":"+activitiesArrayList.get(i).getStartTime()+":"+activitiesArrayList.get(i).getFinishTime()+":"+activitiesArrayList.get(i).getScheduledSequence());
		}
	}
	public void displaySolutionSet() {
		// TODO Auto-generated method stub
		int i;
		System.out.println("Solution");
		for(i=0;i<solutionSet.size();i++)
		{
			System.out.println(solutionSet.get(i));
		}
	}
}
