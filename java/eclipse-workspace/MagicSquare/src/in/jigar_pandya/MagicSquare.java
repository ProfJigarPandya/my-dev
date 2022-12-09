package in.jigar_pandya;

import java.util.Arrays;

public class MagicSquare {
		int n; 
		int[][] squareMatrix;
		public MagicSquare()
		{
			super();
		}
		public MagicSquare(int n) {
			super();
			this.n=n;
			squareMatrix = new int [this.n][this.n];
			// TODO Auto-generated constructor stub
		}
		public void initializeSquareMatrix(int value)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					squareMatrix[i][j]=value;
			}
		}
		public int getN() {
			return n;
		}
		public void setN(int n) {
			this.n = n;
		}
		public int[][] getSquareMatrix() {
			return squareMatrix;
		}
		public void setSquareMatrix(int[][] squareMatrix) {
			this.squareMatrix = squareMatrix;
		}
		public void displaySquareMatrix()
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					System.out.print(squareMatrix[i][j]+" ");
				}
				System.out.print("\n");
			}
			
		}
		public void populateMagicSquareMatrix()
		{
			
			int rowNum, colNum, currentVal=1;
			
			if((n%2)!=1)//Only for odd size of square matrix auto generation starting 1 is supported here for now.
			{
				System.out.println("Only for odd size of square matrix auto generation starting 1 is supported here for now.");
				return;
			}
			

			rowNum=((n/2)+n)%n;
			colNum=((n-1)+n)%n;
			
			//The very first number is always stored at row n/2 and column n-1.
			squareMatrix[rowNum][colNum]=currentVal++;
			System.out.println("rowNum is "+rowNum+" and colNUm is "+colNum);
			
			//Update positioning next number 
			rowNum=(rowNum-1+n)%n;
			colNum=(colNum+1+n)%n;
			do
			{
				System.out.println("rowNum is "+rowNum+" and colNUm is "+colNum);				
				if(squareMatrix[rowNum][colNum]==0)//Check if the position is not taken
				{
					squareMatrix[rowNum][colNum]=currentVal++;
					rowNum=(rowNum-1+n)%n;
					colNum=(colNum+1+n)%n;
				}
				else//If the position is taken already updated row and column in the previous run shall be updated further. row by +1 and column by -2.
				{
					rowNum=(rowNum+1+n)%n;
					colNum=(colNum-2+n)%n;
				}
				
			}while(currentVal<=(n*n));//Do it until we have placed all numbers from 1 to n*n.
		}
		@Override
		public String toString() {
			String str=new String();
			str = "MagicSquare [n=" + n + ",squareMatrix=\n[\n";
			for(int i=0;i<(n-1);i++)
			{
				str+=Arrays.toString(squareMatrix[i])+"\n";
			}
			str+=Arrays.toString(squareMatrix[n-1])+"\n]\n]";
			return str;
		}
		public boolean validateMagicSquareMatrix()
		{
			boolean flag=true;
			int total, expectedTotal=(n *(n*n+1))/2;
			int iterate;
			
			System.out.println("Expected total is "+expectedTotal);
			//Validate rows
			for(iterate=1;iterate<=n;iterate++)
			{
				total=0;
				for(int i=(iterate-1),j=0;j<n;j++)
					total+=squareMatrix[i][j];
				
				if(total!=expectedTotal)
				{
					System.out.println("For the human row iteration "+iterate+" total "+total+" did not meet the expectation.");
					return false;
				}
				System.out.println("For the human row iteration "+iterate+" total is "+total );
			}
			
			//Validate columns
			for(iterate=1;iterate<=n;iterate++)
			{
				total=0;
				for(int i=0,j=(iterate-1);i<n;i++)
					total+=squareMatrix[i][j];
				
				if(total!=expectedTotal)
				{
					System.out.println("For the human column iteration "+iterate+" total "+total+" did not meet the expectation.");
					return false;
				}
				System.out.println("For the human column iteration "+iterate+" total is "+total );
			}
			
			
			//Validate diagonals
			total=0;
			for(int i=0,j=0;i<n;i++,j++)
				total+=squareMatrix[i][j];
			
			if(total!=expectedTotal)
			{
				System.out.println("For the diagonal left top to right bottom, total "+total+" did not meet the expectation.");
				return false;
			}
			System.out.println("For the diagonal left top to right bottom, total is "+total );

			total=0;
			for(int i=n-1,j=n-1;i>=0;i--,j--)
				total+=squareMatrix[i][j];
			
			if(total!=expectedTotal)
			{
				System.out.println("For the diagonal right bottom to left top, total "+total+" did not meet the expectation.");
				return false;
			}
			System.out.println("For the diagonal right bottom to left top, total is "+total );
			
			
			return flag;
		}
}
