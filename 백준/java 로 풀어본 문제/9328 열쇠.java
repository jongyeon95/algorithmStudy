import java.util.*;
import java.io.*;

public class Main{
	public static char[][] map;
	public static boolean[][] visited;
	public static boolean[] keyList;
	public static int n;
	public static int m;
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer stk;
	public static int[] dy={0,0,1,-1};
	public static int[] dx={1,-1,0,0};


	public static void main(String[] args) throws IOException{
		
		int testCase=Integer.parseInt(br.readLine());
		while(testCase-- > 0){
			input();
			System.out.println(stealDocument());
		}
	}

	public static void input() throws IOException {
		stk=new StringTokenizer(br.readLine());
		n=Integer.parseInt(stk.nextToken());
		m=Integer.parseInt(stk.nextToken());
		map=new char[n+2][m+2];
		visited=new boolean[n+2][m+2];
		keyList=new boolean[26];
		for(int i=0; i<n; i++){
			String input=br.readLine();
			for(int j=0; j<m; j++){
				map[i+1][j+1]=input.charAt(j);
			}
		}
		String inputKey=br.readLine();
		if(inputKey.equals("0"))
			return;
		for(int i=0; i<inputKey.length();i++){
			keyList[inputKey.charAt(i)-'a']=true;
		}
	}

	public static int stealDocument(){
		int answer=0;
		visited[0][0]=true;
		Queue<Pair> q= new LinkedList<Pair>();
		q.offer(new Pair(0,0));
		while(!q.isEmpty()){
			Pair p= q.poll();
			for(int i=0; i<4; i++){
				int ty=p.y+dy[i];
				int tx=p.x+dx[i];
				if(ty<0||tx<0||ty>=n+2||tx>=m+2||visited[ty][tx]||map[ty][tx]=='*'){
					continue;
				}
				if(map[ty][tx]>='A'&&map[ty][tx]<='Z'){
					if(keyList[map[ty][tx]-'A']){
						map[ty][tx]='.';
						visited=new boolean[n+2][m+2];
						visited[ty][tx]=true;
						q.offer(new Pair(ty,tx));
					}
				}
				else if(map[ty][tx]>='a'&&map[ty][tx]<='z'){
					keyList[map[ty][tx]-'a']=true;
					map[ty][tx]='.';
					visited=new boolean[n+2][m+2];
					visited[ty][tx]=true;
					q.offer(new Pair(ty,tx));
				}
				else if(map[ty][tx]=='$'){
					answer++;
					map[ty][tx]='.';
					visited=new boolean[n+2][m+2];
					visited[ty][tx]=true;
					q.offer(new Pair(ty,tx));
				}
				else{
					visited[ty][tx]=true;
					q.offer(new Pair(ty,tx));
				}
			}
		}
		return answer;

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

