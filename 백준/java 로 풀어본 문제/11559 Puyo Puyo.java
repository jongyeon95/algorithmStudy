import java.util.*;
import java.io.*;

public class Main{
	public static char[][] map=new char[12][6];
	public static boolean visited[][];
	public static int[] dy={1,-1,0,0};
	public static int[] dx={0,0,1,-1};
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int answer=0;
		for(int i=0; i<12; i++){
			String input=br.readLine();
			for(int j=0; j<6; j++){
				map[i][j]=input.charAt(j);
			}
		}

		while(true){
			boolean check=false;
			visited=new boolean[12][6];
			
			for(int i=0; i<12; i++){
				for(int j=0; j<6; j++){
					if(map[i][j]!='.'){
						if(eraseCube(i,j)){
							check=true;
						}
					}
				}
			}

			if(!check)
				break;

			moveDown();
			answer++;


		}

		System.out.print(answer);
	}

	public static void moveDown(){
		for(int k=1; k<=11; k++){
			for(int i=11; i>=k; i--){
				for(int j=0; j<6; j++){
					if(map[i][j]=='.'&&map[i-1][j]!='.'){
						map[i][j]=map[i-1][j];
						map[i-1][j]='.';
					}
				}
			}
		}
	}

	public static boolean eraseCube(int y, int x){
		
		Queue<Pair> q=new LinkedList<>();
		Queue<Pair> qq=new LinkedList<>();
		char c=map[y][x];
		visited[y][x]=true;
		q.offer(new Pair(y,x));
		
		while(!q.isEmpty()){
			Pair temp=q.poll();
			qq.offer(temp);
			for(int i=0; i<4; i++){
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];
				if(ty<0||tx<0||ty>=12||tx>=6||visited[ty][tx])
					continue;
				if(map[ty][tx]==c){
					visited[ty][tx]=true;
					q.offer(new Pair(ty,tx));
				}

			}
		}

		if(qq.size()>=4){
			while(!qq.isEmpty()){
				Pair temp=qq.poll();
				map[temp.y][temp.x]='.';
			}
			return true;
		}
		return false;

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