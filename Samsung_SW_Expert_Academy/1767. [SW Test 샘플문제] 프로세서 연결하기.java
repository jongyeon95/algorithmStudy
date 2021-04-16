
import java.util.*;
import java.io.*;


class Solution
{
	public static int[][] map;
	public static boolean[][] visited;
	public static ArrayList<Pair> coreList;
	public static int answerCore;
	public static int answerLine;
	public static int n;
	public static int[] dy={0,0,1,-1};
	public static int[] dx={1,-1,0,0};

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;

		int T;
		T=Integer.parseInt(br.readLine());
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			n=Integer.parseInt(br.readLine());
			map=new int[n][n];
			coreList=new ArrayList<>();
			answerCore=0;
			answerLine=0;
			for(int i=0; i<n; i++){
				stk= new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++){
					map[i][j]=Integer.parseInt(stk.nextToken());
					if(map[i][j]==1){
						coreList.add(new Pair(i,j));
					}
				}
			}
			dfs(0,0,0);
			System.out.println("#"+test_case+" "+answerLine);



		}
	}

	public static void dfs(int index, int core, int line){
		if(index>=coreList.size()){
			if(answerCore==core){
				if(answerLine>line)
					answerLine=line;
			}
			else if(answerCore<core){
				answerCore=core;
				answerLine=line;
			}
			return;
		}

		int y=coreList.get(index).y;
		int x=coreList.get(index).x;

		for(int i=0; i<4; i++){
			int ty=y;
			int tx=x;
			int lineCnt=0;
			boolean check=false;
			while(true){
				ty+=dy[i];
				tx+=dx[i];
				if(ty<0||tx<0||ty>=n||tx>=n){
					check=true;
					break;
				}
				if(map[ty][tx]!=0)
					break;
				lineCnt++;
			}
			if(check){
				ty=y;
				tx=x;
				while(true){
					ty+=dy[i];
					tx+=dx[i];
					if(ty<0||tx<0||ty>=n||tx>=n)
						break;
					map[ty][tx]=1;			
				}
				dfs(index+1,core+1,line+lineCnt);
				ty=y;
				tx=x;
				while(true){
					ty+=dy[i];
					tx+=dx[i];
					if(ty<0||tx<0||ty>=n||tx>=n)
						break;
					map[ty][tx]=0;			
				}
			}
		}
		dfs(index+1,core,line);

	}
}

class Pair{
	int y;
	int x;

	public Pair(int y, int x){
		this.y=y;
		this.x=x;
	}
}