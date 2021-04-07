import java.util.*;
import java.io.*;

public class Main{
	
	public static int[][][][] blocks= new int[5][4][5][5]; //입력 1 , 회전수  , 세로 , 가로
	public static int[] floor=new int[5];
	public static int[] shape=new int[5];
	public static boolean[] floorCheck=new boolean[5];
	public static int answer;
	public static void main(String[] args) throws IOException{
		init();
		makeFloor(0);
		if(answer==987654321)
			answer=-1;
		System.out.println(answer);

	}

	public static int solved(){
		int result=987654321;
		int[] dy={1,-1,0,0,0,0};
		int[] dx={0,0,1,-1,0,0};
		int[] dz={0,0,0,0,1,-1};
		boolean[][][] visited=new boolean[5][5][5];
		int [][][] map = new int[5][5][5];
		
		for(int k=0; k<5; k++){
			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					map[k][i][j]=blocks[floor[k]][shape[k]][i][j];
				}
			}
		}
		if(map[0][0][0]==0||map[4][4][4]==0)
			return 987654321;
		visited[0][0][0]=true;
		Queue<Node> q = new LinkedList<Node>();
		q.offer(new Node(0,0,0,0));
		while(!q.isEmpty()){
			Node temp = q.poll();
			for(int i=0; i<6; i++){
				int ty=dy[i]+temp.y;
				int tx=dx[i]+temp.x;
				int tz=dz[i]+temp.z;
				if(ty<0||tx<0||tz<0||ty>=5||tx>=5||tz>=5||visited[ty][tx][tz]||map[ty][tx][tz]==0)
					continue;
				if(ty==4&&tx==4&&tz==4){
					if(temp.cnt+1<result)
						result=temp.cnt+1;
					continue;
				}
				visited[ty][tx][tz]=true;
				q.offer(new Node(ty,tx,tz,temp.cnt+1));
			}
		}
		return result;


	}

	public static void makeShape(int index){
		
		if(index>=5){
			int result=solved();
			if(result<answer)
				answer=result;
			return;
		}

		for(int i=0; i<4; i++){
			shape[index]=i;
			makeShape(index+1);
		}
	}

	public static void makeFloor(int index){
		if(index>=5){
			makeShape(0);
			return;
		}

		for(int i=0; i<5; i++){
			if(!floorCheck[i]){
				floorCheck[i]=true;
				floor[index]=i;
				makeFloor(index+1);
				floorCheck[i]=false;
			}
		}
	}

	

	public static void init() throws IOException {
		answer=987654321;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;
		for(int k=0; k<5; k++){
			for(int i=0; i<5; i++){
				stk=new StringTokenizer(br.readLine());
				for(int j=0; j<5; j++){
					blocks[k][0][i][j]=Integer.parseInt(stk.nextToken());
				}
			}
			
			for(int z=1; z<4; z++){
				for(int i=0; i<5; i++){
					for(int j=0; j<5; j++){
						blocks[k][z][i][j]=blocks[k][z-1][4-j][i];
					}
				}
			}
			
		}
	}
}

class Node{
	int y;
	int x;
	int z;
	int cnt;
	public Node(int y, int x, int z, int cnt){
		this.y=y;
		this.x=x;
		this.z=z;
		this.cnt=cnt;
	}	
}