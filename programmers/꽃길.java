import java.util.*;
import java.io.*;

public class Main{

	public static int map[][];
	public static int answer=Integer.MAX_VALUE;
	public static boolean visited[][];
	public static int dy[]={0,0,0,1,-1};
	public static int dx[]={0,1,-1,0,0};
	
	public static void main(String arg[]) throws IOException{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(stk.nextToken());
		map=new int[n][n];
		visited=new boolean[n][n];
		for (int i=0; i<n; i++){
			stk = new StringTokenizer(br.readLine());
			for (int j=0; j<n; j++){
				map[i][j]=Integer.parseInt(stk.nextToken());
			}
		}
		solved(0,0,1);
		System.out.println(answer);
	}

	public static void solved(int count, int num,int y){
		if(count>=3){
			if(answer>num)
				answer=num;
			return;
		}
		for(int i=y; i<map.length-1; i++){
			for(int j=1; j<map.length-1; j++){
				boolean check=true;
				
				for(int k=0; k<5; k++){
					if(visited[i+dy[k]][j+dx[k]]){
						check=false;
						break;
					}
				}
				
				if(check){
					int cnt=0;
					for(int k=0; k<5; k++){
						visited[i+dy[k]][j+dx[k]]=true;
						cnt+=map[i+dy[k]][j+dx[k]];				
					}
					solved(count+1,num+cnt,i);
					for(int k=0; k<5; k++){
						visited[i+dy[k]][j+dx[k]]=false;
					}
				}
			}
		}
	}
}