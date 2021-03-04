import java.util.*;
import java.io.*;

public class Main{
	
	public static int n;
	public static int e;
	public static int v1;
	public static int v2;
	public static int[][] road;
	public static int INF=200000000;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		n=Integer.parseInt(stk.nextToken());
		e=Integer.parseInt(stk.nextToken());
		road=new int[n+1][n+1];
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				road[i][j]=INF;
				if(i==j)
					road[i][j]=0;
			}
		}
		for(int i=0; i<e; i++){
			stk = new StringTokenizer(br.readLine());
			int a=Integer.parseInt(stk.nextToken());
			int b=Integer.parseInt(stk.nextToken());
			int c=Integer.parseInt(stk.nextToken());
			road[a][b]=c;
			road[b][a]=c;
		}
		stk = new StringTokenizer(br.readLine());
		v1=Integer.parseInt(stk.nextToken());
		v2=Integer.parseInt(stk.nextToken());


		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(i==j)
						continue;
					if(road[i][j]>road[i][k]+road[k][j]){
						road[i][j]=road[i][k]+road[k][j];
					}
				}
			}
		}
		int v1First=road[1][v1]+road[v1][v2]+road[v2][n];
		int v2First=road[1][v2]+road[v2][v1]+road[v1][n];
		
		

		
		int answer= v1First < v2First ? v1First:v2First;
		if(answer>=INF)
			answer=-1;
		System.out.print(answer);

	}

}