import java.util.*;
import java.io.*;

public class Main{
	public static int[][] dp;
	public static int[][] map;
	public static int INF=16000000;
	public static int n;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		n=Integer.parseInt(br.readLine());
		map=new int[n][n];
		dp=new int[n][(1<<n)-1];

		for(int i = 0 ; i < n; i++)
            Arrays.fill(dp[i], INF);

		for(int i = 0 ; i < n ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        bw.write(tsp(0, 1)+"\n");
        bw.flush();
        br.close();
        bw.close();
	}

	public static int tsp(int node, int visit){
		if(visit==(1<<n)-1){
			if(map[node][0]==0){
				return INF;
			}
			return map[node][0];
		}

		if(dp[node][visit] != INF)
            return dp[node][visit];

        for(int i = 0 ; i < n; i++){
            int next = visit | (1 << i);
            if(map[node][i] == 0 || (visit & (1 << i)) != 0) continue;

            dp[node][visit] = Math.min(dp[node][visit], tsp(i, next) + map[node][i]);
        }

        return dp[node][visit];

	}
}