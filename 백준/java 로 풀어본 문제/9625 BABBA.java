import java.io.*;
import java.util.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		Pair[] dp = new Pair[45];
		dp[0]=new Pair(0,1);
		for(int i=1; i<k; i++){
			dp[i]=new Pair(dp[i-1].b,dp[i-1].a+dp[i-1].b);
			
		}
		System.out.println(dp[k-1].a+" "+dp[k-1].b);
		
	}
}

class Pair{
	int a;
	int b;

	public Pair(int a , int b){
		this.a=a;
		this.b=b;
	}
}