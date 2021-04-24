import java.util.*;
import java.io.*;

public class Main{
	public static int col;
	public static int row;
	public static int[][] map;
	public static int[] dy={-1,0,1,0}; // 북동남서
	public static int[] dx={0,1,0,-1};
	public static ArrayList<Robot> list;
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer stk = new StringTokenizer(br.readLine());
		row=Integer.parseInt(stk.nextToken());
		col=Integer.parseInt(stk.nextToken());
		map=new int[col][row];
		stk = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(stk.nextToken());
		int m=Integer.parseInt(stk.nextToken());
		list=new ArrayList<Robot>();
		list.add(new Robot(-1,-1,'W'));
		for(int i=0; i<n; i++){
			stk = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(stk.nextToken())-1;
			int y = Integer.parseInt(stk.nextToken());
			char c = stk.nextToken().charAt(0);
			y=col-y;
			list.add(new Robot(y,x,c));
			map[y][x]=i+1;
		}
		for(int i=0; i<m; i++){
			stk = new StringTokenizer(br.readLine());
			int rIndex=Integer.parseInt(stk.nextToken());
			char c = stk.nextToken().charAt(0);
			int cnt = Integer.parseInt(stk.nextToken());
			
			if(!action(rIndex,c,cnt)){
				bw.flush();
				bw.close();
				return;
			}
		}
		bw.write("OK");
		bw.flush();
		bw.close();
		return;

	}
	public static boolean action(int index, char c , int cnt) throws IOException{
		if(c=='R'){
			int dir=list.get(index).dir;
			for(int i=0; i<cnt; i++){
				dir++;
				if(dir>3)
					dir=0;
			}
			list.get(index).dir=dir;
			return true;
		}
		else if(c=='L'){
			int dir=list.get(index).dir;
			for(int i=0; i<cnt; i++){
				dir--;
				if(dir<0)
					dir=3;
			}
		
			list.get(index).dir=dir;
			return true;
		}
		else{
			int ty=list.get(index).y;
			int tx=list.get(index).x;
			int dir=list.get(index).dir;		
			for(int i=0; i<cnt; i++){
				map[ty][tx]=0;
				ty=dy[dir]+ty;
				tx=dx[dir]+tx;
				if(ty<0||tx<0||ty>=col||tx>=row){
					bw.write("Robot "+index+" crashes into the wall");
					return false;
				}
				if(map[ty][tx]!=0){
					bw.write("Robot "+index+" crashes into robot "+map[ty][tx]);
					return false;
				}
				else{
					map[ty][tx]=index;
				}
			}
			list.get(index).y=ty;
			list.get(index).x=tx;
			return true;
		}
	}
}

class Robot{
	int y;
	int x;
	int dir;
	public Robot(int y, int x , char c){
		this.y=y;
		this.x=x;
		if(c=='N') this.dir=0;
		else if(c=='E') this.dir=1;
		else if(c=='S') this.dir=2;
		else  this.dir=3;
	}
}