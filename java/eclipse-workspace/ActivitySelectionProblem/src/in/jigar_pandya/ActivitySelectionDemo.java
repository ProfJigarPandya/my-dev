package in.jigar_pandya;

public class ActivitySelectionDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Hello World");
		ActivitySelectionProblem obj = new ActivitySelectionProblem();
		obj.insertAllActivityDetails();
		obj.displayAllActivityDetails();
		obj.applyActivitySelectionAlgo();
		System.out.println("After applying acitivity selection algorithm, result is as below: ");
		obj.displaySchedule();
		obj.displaySolutionSet();
	}

}
