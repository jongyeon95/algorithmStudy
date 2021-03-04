import java.util.*;
import java.io.*;

public class Main{

	public static int square[]={0,5,5,5,5,5};
	public static int map[][];
	public static boolean visited[][];
	public static int answer;
	public static int squareCnt;

	public static void main(String[] args) throws IOException{
		init();
		dfs(0,0,0,0);
		if(answer==Integer.MAX_VALUE)
			answer=-1;
		System.out.println(answer);
	}


	public static void dfs(int y, int x, int cnt, int result){

		if(cnt==squareCnt&&answer>result){
			answer=result;
			return;
		}


		if(answer<result) return;

		if(x>9){
			dfs(y+1,0,cnt,result);
			return;
		}
		if(y>9)
			return;
		
		if(map[y][x]==1&&!visited[y][x]){
		for(int k=5; k>=1; k--){
			if(square[k]>0&&y+k<=10&&x+k<=10){
				boolean check=true;
				for(int i=y; i<y+k; i++){
					for(int j=x; j<x+k; j++){
						if(map[i][j]==0||visited[i][j]){
							check=false;
							break;
						}
					}
					if(!check)
						break;
				}
				if(check){
					square[k]--;
					for(int i=y; i<y+k; i++){
						for(int j=x; j<x+k; j++){
							visited[i][j]=true;
						}
					}
					dfs(y,x+1,cnt+(k*k),result+1);
					square[k]++;
					for(int i=y; i<y+k; i++){
						for(int j=x; j<x+k; j++){
							visited[i][j]=false;
						}
					}
				}
			}
		}
		}
		else{
			dfs(y,x+1,cnt,result);
		}
		


	}

	public static void init() throws IOException {
		map= new int[10][10];
		visited=new boolean[10][10];
		answer=Integer.MAX_VALUE;
		squareCnt=0;

		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;

		for(int i=0; i<10; i++){
			stk= new StringTokenizer(br.readLine());
			for(int j=0; j<10; j++){
				map[i][j]=Integer.parseInt(stk.nextToken());
				if(map[i][j]==1)
					squareCnt++;
			}
		}

	}

}