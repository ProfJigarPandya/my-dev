package in.jigar_pandya;

public class Activity {
	int activityID;
	int startTime;
	int finishTime;
	int scheduledSequence;
  
	
	public Activity() {
		// TODO Auto-generated constructor stub
	}
	
	public Activity(int activityID, int startTime, int finishTime) {
		super();
		this.activityID = activityID;
		this.startTime = startTime;
		this.finishTime = finishTime;
		this.scheduledSequence=-1; // -1 Indicates neither selected nor rejected as of now while greedy selection is performed.
									// 0 Indicates rejected
									// 1 or more will indicate the sequence finalized. 1st to be 1st activity to be allowed the access to resource. 
	}

	public int getActivityID() {
		return activityID;
	}
	public void setActivityID(int activityID) {
		this.activityID = activityID;
	}
	public int getStartTime() {
		return startTime;
	}
	public void setStartTime(int startTime) {
		this.startTime = startTime;
	}
	public int getFinishTime() {
		return finishTime;
	}

	public void setFinishTime(int finishTime) {
		this.finishTime = finishTime;
	}
	@Override
	public String toString() {
		return "Activity [activityID=" + activityID + ", startTime=" + startTime + ", finishTime=" + finishTime + "]";
	}

	public int getScheduledSequence() {
		return scheduledSequence;
	}

	public void setScheduledSequence(int scheduledSequence) {
		this.scheduledSequence = scheduledSequence;
	}
	
	
};
