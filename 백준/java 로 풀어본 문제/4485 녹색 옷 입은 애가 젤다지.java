import java.util.*;
import java.io.*;

public class Main{
	public static int[][] map;
	public static int[][] cost;
	public static final int INF=987654321;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer stk;
		int testIndex=0;
		while(true){
			testIndex++;
			int size=Integer.parseInt(br.readLine());
			if(size==0)
				break;
			map=new int[size][size];
			cost=new int[size][size];
			for(int i=0; i<size; i++){
				stk=new StringTokenizer(br.readLine());
				for(int j=0; j<size; j++){
					map[i][j]=Integer.parseInt(stk.nextToken());
					cost[i][j]=INF;
				}
			}
			int[] dy={0,0,-1,1};
			int[] dx={1,-1,0,0};
			Queue<Pair> q= new LinkedList<>();
			q.offer(new Pair(0,0));
			cost[0][0]=map[0][0];
			while(!q.isEmpty()){
				Pair temp=q.poll();
				if(temp.y==size-1&&temp.x==size-1)
					continue;
				for(int i=0; i<4; i++){
					int ty=temp.y+dy[i];
					int tx=temp.x+dx[i];
					if(ty<0||tx<0||ty>=size||tx>=size)
						continue;
					if(cost[temp.y][temp.x]+map[ty][tx]<cost[ty][tx]){
						cost[ty][tx]=cost[temp.y][temp.x]+map[ty][tx];
						q.offer(new Pair(ty,tx));
					}
				}
			}
			bw.write("Problem "+testIndex+": "+cost[size-1][size-1]+"\n");


		}
		bw.flush();
		bw.close();
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
