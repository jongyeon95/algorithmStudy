import java.io.IOException; 
import java.util.Scanner;
public class Main { 
	public static void main(String[] args) throws IOException {

	Scanner sc=new Scanner(System.in);
		boolean Ascencding=true;
		boolean Decending=true;
		int[] input = new int[8];
		for(int i=0; i<8; i++){
			input[i]=sc.nextInt();
		}
		for (int i=1;i<8;i++) {
			if (input[i]>input[i-1]){
				Decending=false;
			}
			else if(input[i]<input[i-1]){
				Ascencding=false;
			}
		}

		if (Decending){
			System.out.print("descending");
		}
		else if(Ascencding){
			System.out.print("ascending");
		}
		else{
			System.out.print("mixed");
		}
	} 
}

