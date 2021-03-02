import java.util.*;
import java.io.*;

class Monkey{
	
	int count;
	int hmove;
	int y;
	int x;

	public Monkey(int y, int x, int count, int hmove){
		this.y=y;
		this.x=x;
		this.count=count;
		this.hmove=hmove;
	}
}


public class Main{
	
	public static int k;
	public static int col;
	public static int row;
	public static int answer;
	public static int map[][];
	public static boolean visited[][][];
	public static int hdy[]={1,2,2,1,-1,-2,-2,-1};
	public static int hdx[]={-2,-1,1,2,2,1,-1,-2};
	public static int dy[]={0,0,1,-1};
	public static int dx[]={1,-1,0,0};


	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		k=Integer.parseInt(br.readLine());
		StringTokenizer stk = new StringTokenizer(br.readLine());
		
		row=Integer.parseInt(stk.nextToken());
		col=Integer.parseInt(stk.nextToken());
		map=new int[col][row];
		visited=new boolean[col][row][k+1];
		answer=Integer.MAX_VALUE;

		for(int i=0; i<col; i++){
			stk=new StringTokenizer(br.readLine());
			for(int j=0; j<row; j++){
				map[i][j]=Integer.parseInt(stk.nextToken());
			}
		}

		Queue<Monkey> q= new LinkedList<Monkey>();
		q.offer(new Monkey(0,0,0,k));
		visited[0][0][k]=true;
		while(!q.isEmpty()){
			Monkey temp = q.poll();
			if(temp.y==col-1&&temp.x==row-1){
				if(temp.count<answer)
					answer=temp.count;
				continue;
			}

			if(temp.hmove>0){
				for(int i=0; i<8; i++){
					int ty=temp.y+hdy[i];
					int tx=temp.x+hdx[i];
					if(ty<0||tx<0||ty>=col||tx>=row||visited[ty][tx][temp.hmove-1]||map[ty][tx]==1){
						continue;
					}
					visited[ty][tx][temp.hmove-1]=true;
					q.offer(new Monkey(ty,tx,temp.count+1,temp.hmove-1));
				}
			}

			for(int i=0; i<4; i++){
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];
				if(ty<0||tx<0||ty>=col||tx>=row||visited[ty][tx][temp.hmove]||map[ty][tx]==1){
					continue;
				}
				visited[ty][tx][temp.hmove]=true;
				q.offer(new Monkey(ty,tx,temp.count+1,temp.hmove));
			}
		}
		if(answer==Integer.MAX_VALUE)
			answer=-1;
		System.out.println(answer);
	}
}