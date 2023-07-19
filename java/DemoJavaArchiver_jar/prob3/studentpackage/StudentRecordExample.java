package studentpackage;
public class StudentRecordExample
{
	public static void main(String args[])
	{

		StudentRecord studentRecord = new StudentRecord();

		StudentRecord anotherStudentRecord = new StudentRecord();


		StudentRecord thirdStudentRecord = new StudentRecord();

		studentRecord.setName("FirstStudentName");
		anotherStudentRecord.setName("AnotherStudentName");
		thirdStudentRecord.setName("ThirdStudentName");

		System.out.println("First Student : "+studentRecord.getName());
		System.out.println("Second Student : "+anotherStudentRecord.getName());
		System.out.println("Third Student : "+thirdStudentRecord.getName());

	}

}

