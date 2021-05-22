import java.util.*;
import java.io.*;

public class Main{
	public static int[][] map;
	public static int[][] cost;
	public static final int INF=987654321;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int size=Integer.parseInt(br.readLine());
		map=new int[size][size];
		cost=new int[size][size];
		for(int i=0; i<size; i++){
			String input=br.readLine();
			for(int j=0; j<size; j++){
				map[i][j]=input.charAt(j)-'0';
				if(map[i][j]==1) map[i][j]=0;
				else map[i][j]=1;
				cost[i][j]=INF;
			}
		}
		cost[0][0]=0;
		Queue<Pair> q= new LinkedList<>();
		q.offer(new Pair(0,0));
		int[] dy={0,0,1,-1};
		int[] dx={1,-1,0,0};
		while(!q.isEmpty()){
			Pair temp = q.poll();
			for(int i=0; i<4; i++){
				int ty=dy[i]+temp.y;
				int tx=dx[i]+temp.x;
				if(ty<0||tx<0||ty>=size||tx>=size)
					continue;
				if(cost[temp.y][temp.x]+map[ty][tx]<cost[ty][tx]){
					cost[ty][tx]=cost[temp.y][temp.x]+map[ty][tx];
					q.offer(new Pair(ty,tx));
				}
			}
		}

		bw.write(""+cost[size-1][size-1]);
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
