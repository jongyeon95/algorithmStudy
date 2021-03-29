import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		int anwser=0;
		int[][] dp=new int[a.length()+1][b.length()+1];
		for(int i=1;i<=a.length(); i++){
			for(int j=1;j<=b.length();j++){
				if(a.charAt(i-1)==b.charAt(j-1)){
					dp[i][j]=dp[i-1][j-1]+1;
					if(dp[i][j]>anwser)
						anwser=dp[i][j];
				}
			}
		}
		System.out.println(anwser);
	}
}