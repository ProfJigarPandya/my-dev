package in.jigar_pandya;

public class DemoMagicSquare {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MagicSquare msObj=new MagicSquare(7);
		msObj.initializeSquareMatrix(0);
		//msObj.displaySquareMatrix();
		msObj.populateMagicSquareMatrix();
		System.out.println("Magic square of size "+msObj.n);
		//msObj.displaySquareMatrix();
		System.out.println(msObj);
		System.out.println(msObj.validateMagicSquareMatrix());		
	}
}
