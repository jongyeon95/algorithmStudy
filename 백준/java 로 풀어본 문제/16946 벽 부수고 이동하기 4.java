import java.util.*;
import java.io.*;

public class Main
{
	public static int[] dy={0,0,1,-1};
	public static int[] dx={1,-1,0,0};
 	public static int y;
 	public static int x;
 	public static int areaIndex;
 	public static int[][] map;
 	public static boolean[][] visited;
 	public static HashMap<Integer,Integer> hm=new HashMap<>();
 	
 	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		StringTokenizer stk = new StringTokenizer(br.readLine());

		y=Integer.parseInt(stk.nextToken());
		x=Integer.parseInt(stk.nextToken());
		map=new int[y][x];
		areaIndex=-1;
		
		for(int i=0; i<y; i++){
			String input=br.readLine();
			for(int j=0; j<x; j++){
				map[i][j]=input.charAt(j)-'0';
			}
		}

		for(int i=0; i<y; i++){
			for(int j=0; j<x; j++){
				if(map[i][j]==0){
					divideArea(i,j);
					areaIndex--;
				}
				
			}
			
		}
	

		for(int i=0; i<y; i++){
			for(int j=0; j<x; j++){
				if(map[i][j]==1){
					map[i][j]=breakWall(i,j);			
				}
			}
		}

		for(int i=0; i<y; i++){
			for(int j=0; j<x; j++){
				if(map[i][j]<0){
					map[i][j]=0;		
				}
				bw.write(String.valueOf(map[i][j]%10));
			}
			bw.write("\n");
		}
		bw.flush();
		bw.close();
		br.close();



	
	}

	public static void divideArea(int yy, int xx){
		Queue<Pair> q= new LinkedList<>();
		map[yy][xx]=areaIndex;
		int cnt=0;
		q.offer(new Pair(yy,xx));
		while(!q.isEmpty()){
			Pair temp = q.poll();
			cnt++;
			for(int i=0; i<4; i++){
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];
				if(ty<0||tx<0||ty>=y||tx>=x||map[ty][tx]!=0){
					continue;
				}
				map[ty][tx]=areaIndex;
				q.offer(new Pair(ty,tx));
			}
		}
		hm.put(areaIndex,cnt);
	}

	public static int breakWall(int yy, int xx){
		int sum=1;
		HashSet<Integer> hs=new HashSet<>();
		for(int i=0; i<4; i++){
			int ty=yy+dy[i];
			int tx=xx+dx[i];
			if(ty<0||tx<0||ty>=y||tx>=x){
				continue;
			}
			if(map[ty][tx]<0){
				hs.add(map[ty][tx]);
			}
		}
		for(int temp : hs){
			sum+=hm.get(temp);
		}
		return sum;
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
