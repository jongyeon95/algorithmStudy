import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) throws IOException{
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int answer=0;
		int list[]=new int[n];
		for(int i=0; i<n; i++){
			list[i]=sc.nextInt();
		}
		for(int i=0; i<n; i++){
			int temp=list[i];
			int left=i;
			int right=i;
			for(int j=i; j>=0; j--){
				if(list[j]<temp){
					left=j+1;
					break;
				}
				left=j;
			}
			for(int j=i; j<n; j++){
				if(list[j]<temp){
					right=j-1;
					break;
				}
				right=j;
			}
			
			if(left==right){
				if(temp>answer)
					answer=temp;
			}
			else{
				if((right-left+1)*temp>answer)
					answer=(right-left+1)*temp;

			}
		}
		
		System.out.print(answer);
	}
}