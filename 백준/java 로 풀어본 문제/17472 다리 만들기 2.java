import java.util.*;
import java.io.*;

public class Main{

	public static int n;
	public static int m;
	public static int[][] map;
	public static int[][] bridge;
	public static int[] dy={0,1,0,-1};
	public static int[] dx={1,0,-1,0};
	public static int[] area;
	public static int areaCnt;



	public static void main(String[] args) throws IOException{
		init();

		areaCnt=findArea();
		init2();
		makeBridge();
		System.out.println(connectBridge());


	}

	public static int connectBridge(){
		int result=0;
		int cnt=0;
		PriorityQueue<Vertex> pq= new PriorityQueue<>();
		for(int i=1; i<=areaCnt; i++){
			for(int j=i; j<=areaCnt; j++){
				if(bridge[i][j]!=Integer.MAX_VALUE){
					pq.offer(new Vertex(i,j,bridge[i][j]));
				}
			}
		}

		while(!pq.isEmpty()){
			Vertex temp=pq.poll();
			if(union(temp.start,temp.end)){
				result+=bridge[temp.start][temp.end];
				cnt++;
			}
		}
		if(result==0)
			return -1;
		if(cnt!=areaCnt-1)
			return -1;
		return result;


	}

	public static int find(int x){
		if(area[x]==x){
			return x;
		}
		return find(area[x]);
	}
	
	public static boolean union(int x, int y){
		int tx=find(x);
		int ty=find(y);
		if(ty==tx)
			return false;
		area[ty]=tx;
		return true;
	}

	public static void init() throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		n=Integer.parseInt(stk.nextToken());
		m=Integer.parseInt(stk.nextToken());
		map=new int[n][m];
		for(int i=0; i<n; i++){
			stk = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++){
				map[i][j]=Integer.parseInt(stk.nextToken());
				if(map[i][j]==1)
					map[i][j]=-1;
			}
		}
	}
	public static void init2(){
		bridge=new int[areaCnt+1][areaCnt+1];
		area=new int[areaCnt+1];
		for(int i=0; i<=areaCnt; i++){
			for(int j=0; j<=areaCnt; j++){
				bridge[i][j]=Integer.MAX_VALUE;
			}
		}
		for(int i=0; i<=areaCnt; i++){
			area[i]=i;
		}

	}

	public static int findArea(){
		int cnt=1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(map[i][j]==-1){
					fillArea(i,j,cnt);
					cnt++;
				}
			}
		}
		return cnt-1;
	}

	public static void fillArea(int y , int x, int cnt){
		Queue<Pair> q = new LinkedList<>();
		q.offer(new Pair(y,x));
		map[y][x]=cnt;
		
		while(!q.isEmpty()){
			Pair p = q.poll();
			for(int i=0;i<4; i++){
				int ty=p.y+dy[i];
				int tx=p.x+dx[i];
				if(ty<0||tx<0||ty>=n||tx>=m)
					continue;
				if(map[ty][tx]==-1){
					map[ty][tx]=cnt;
					q.offer(new Pair(ty,tx));
				}
			}
		}
	}

	public static void makeBridge(){
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(map[i][j]!=0){
					for(int k=0; k<2; k++){
						int ty=i+dy[k];
						int tx=j+dx[k];
						if(ty<n&&tx<m&&map[ty][tx]==0){
							Bridge temp=findBridge(ty,tx,k);
							if(temp.length!=-1&&bridge[map[i][j]][temp.area]>temp.length){
								bridge[map[i][j]][temp.area]=temp.length;
								bridge[temp.area][map[i][j]]=temp.length;
							}
						}
					}
				}
			}
		}

	}

	public static Bridge findBridge(int y, int x, int dir){
		int cnt=0;
		int ty=y;
		int tx=x;
		while(true){
			if(ty>=n||tx>=m){
				return new Bridge(-1,-1);
			}
			if(map[ty][tx]!=0){
				if(cnt<2)
					return new Bridge(-1,-1);
				return new Bridge(map[ty][tx],cnt);
			}
			ty+=dy[dir];
			tx+=dx[dir];
			cnt++;
		}
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

class Bridge{
	int area;
	int length;
	public Bridge(int area, int length){
		this.area=area;
		this.length=length;
	}
}

class Vertex implements Comparable<Vertex>{
	int start;
	int end;
	int cost;
	public Vertex(int start, int end, int cost){
		this.start=start;
		this.end=end;
		this.cost=cost;
	}

	@Override
	public int compareTo(Vertex o){
		return this.cost-o.cost;
	}
}