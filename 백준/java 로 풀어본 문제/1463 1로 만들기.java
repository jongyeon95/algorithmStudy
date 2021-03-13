import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int[] dp = new int[n+1];
		for(int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + 1;
			if(i % 2 == 0)
				dp[i] = Math.min(dp[i], dp[i/2] + 1);
			if(i % 3 == 0)
				dp[i] = Math.min(dp[i], dp[i/3] + 1);	
		}
		System.out.println(dp[n]);
	}
}