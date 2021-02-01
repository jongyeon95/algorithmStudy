import java.util.*;
import java.io.*;

public class Main{


	public static boolean visited[][];
	public static double dir[]=new double[4];
	public static double success=0;
	public static int dyx[][]={{0,1},{0,-1},{1,0},{-1,0}};
	public static int n;
	public static void main(String arg[]) throws IOException{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stk.nextToken());
		visited=new boolean[n*2+1][n*2+1];
		for (int i=0; i<4; i++){
			dir[i]=Integer.parseInt(stk.nextToken())*0.01;
		}
		visited[n][n]=true;
		solved(n,n,1,0);
		
		System.out.println(success);
		
	}

	public static void solved(int y, int x, double num ,int cnt){
		if(cnt==n){
			success+=num;
			return;
		}
		for(int i=0; i<4; i++){
			int ty=y+dyx[i][0];
			int tx=x+dyx[i][1];
			if(visited[ty][tx]){
				continue;
			}
			visited[ty][tx]=true;
			solved(ty,tx,num*dir[i],cnt+1);
			visited[ty][tx]=false;
		}
	}
}