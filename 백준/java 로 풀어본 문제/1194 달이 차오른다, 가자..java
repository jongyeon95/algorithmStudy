import java.util.*;
import java.io.*;

public class Main
{
	public static int col;
	public static int row;
	public static char[][] map;
	public static boolean[][][] visited;
	public static int[] keyIndex={1,2,4,8,16,32};
	public static int[] dy={0,0,1,-1};
	public static int[] dx={1,-1,0,0};
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk=new StringTokenizer(br.readLine());
		col=Integer.parseInt(stk.nextToken());
		row=Integer.parseInt(stk.nextToken());
		map=new char[col][row];
		visited= new boolean[col][row][2*2*2*2*2*2];
		Minsik start=new Minsik(0,0,0,0);
		for(int i=0; i<col; i++){
			String input=br.readLine();
			for(int j=0; j<row; j++){
				map[i][j]=input.charAt(j);
				if(map[i][j]=='0'){
					map[i][j]='.';
					start.y=i;
					start.x=j;
				}
			}
		}
		System.out.println(bfs(start));

		
		
	}

	public static int bfs(Minsik start){
		int answer=-1;
		Queue<Minsik> q = new LinkedList<Minsik>();
		q.offer(start);
		visited[start.y][start.x][0]=true;
		while(!q.isEmpty()){
			Minsik temp = q.poll();
			if(answer!=-1&&answer<temp.move)
				continue;

			for(int i=0; i<4; i++){
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];
				if(ty<0||tx<0||ty>=col|tx>=row||map[ty][tx]=='#')
					continue;
				if(visited[ty][tx][temp.key])
					continue;
				if(map[ty][tx]=='.'){
					visited[ty][tx][temp.key]=true;
					q.offer(new Minsik(ty,tx,temp.key,temp.move+1));
				}
				else if(map[ty][tx]>='A'&&map[ty][tx]<='F'){
					int tempDoor= (1<<(map[ty][tx]-'A'));
					if((temp.key & tempDoor)>0){
						visited[ty][tx][temp.key]=true;
						q.offer(new Minsik(ty,tx,temp.key,temp.move+1));
					}
				}
				else if(map[ty][tx]>='a'&&map[ty][tx]<='f'){
					int tempKey=(temp.key | (1<<map[ty][tx]-'a'));
					visited[ty][tx][tempKey]=true;
					q.offer(new Minsik(ty,tx,tempKey,temp.move+1));

				}
				else if(map[ty][tx]=='1'){
					if(answer==-1){
						answer=temp.move+1;
					}
					else if(answer>temp.move+1){
						answer=temp.move+1;
					}
				}
			}
		}
		return answer;
	}
	
}

class Minsik{
	int y;
	int x;
	int key;
	int move;

	public Minsik(int y, int x, int key, int move){
		this.y=y;
		this.x=x;
		this.key=key;
		this.move=move;
	}
}

