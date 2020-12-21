import java.io.IOException; 
import java.util.Scanner;

public class Main { 
	public static void main(String[] args) throws IOException {
		Scanner s=new Scanner(System.in);
 
        int t = s.nextInt();
        int w = s.nextInt();
 
        
        int[][] dp = new int[t+1][w+1];
 
        for(int i=1; i<=t; i++) {
            int tree = s.nextInt();
 
            for(int j=0; j<=w; j++) {
               
                if(j == 0) {
                    if(tree == 1) 
                        dp[i][j] = dp[i-1][j] + 1;
                    else            
                        dp[i][j] = dp[i-1][j];
 
                    continue;
                }
 
                
                if(j%2 == 0) {
                    if(tree == 1) 
                        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j] + 1);
                    else 
                        dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j]);
                }
                
                else {
                    if(tree == 1)
                        dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j]);
                    else
                        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j] + 1);
                }
            }
        }
 
        int ans = 0;
        for(int i=0; i<=w; i++)
            ans = max(ans, dp[t][i]);
 
        System.out.println(ans);
    }
 
    
	static int max(int a, int b) {
        return (a > b) ? a : b;
    }
}

