import java.util.*;
import java.io.*;

public class Main
{
	public static int n;
	public static int m;
	public static int x;
	public static int[][] map;
	public static int INF=Integer.MAX_VALUE/2;

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		n=Integer.parseInt(stk.nextToken());
		m=Integer.parseInt(stk.nextToken());
		x=Integer.parseInt(stk.nextToken());
		map=new int[n+1][n+1];
		
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				map[i][j]=INF;
			}
		}

		
		for(int i=0; i<m; i++){
			stk = new StringTokenizer(br.readLine());
			int start=Integer.parseInt(stk.nextToken());
			int end=Integer.parseInt(stk.nextToken());
			int weight=Integer.parseInt(stk.nextToken());
			map[start][end]=weight;
		}

		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(i==j) continue;
					if(map[i][k]!=INF&&map[k][j]!=INF&&map[i][j]>map[i][k]+map[k][j]){
						map[i][j]=map[i][k]+map[k][j];
					}
				}
			}
		}
		int answer=0;
		for(int i=1; i<=n; i++){
			if(i==x) continue;
			if(map[i][x]+map[x][i]>answer){
				answer=map[i][x]+map[x][i];
			}
		}
		System.out.print(answer);

	}

}


