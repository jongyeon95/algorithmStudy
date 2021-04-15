import java.util.*;
import java.io.*;


public class Main{
	static int N, map[][], result;
	static int dx[]= {0,1,0,-1};
	static int dy[]= {-1,0,1,0};
	static int percent[]= {1,1,2,2,5,7,7,10,10};
	static int movex[][]= {
			{-1,1,-2,2,0,-1,1,-1,1,0}, //좌
			{0,0,1,1,3,1,1,2,2,2}, //하
			{-1,1,-2,2,0,-1,1,-1,1,0}, //우
			{0,0,-1,-1,-3,-1,-1,-2,-2,-2} //상
	
	};
	static int movey[][]= {
			{0,0,-1,-1,-3,-1,-1,-2,-2,-2}, //좌
			{-1,1,-2,2,0,-1,1,-1,1,0}, //하
			{0,0,1,1,3,1,1,2,2,2}, //우
			{-1,1,-2,2,0,-1,1,-1,1,0} //상
	};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());

		map = new int[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve(1,0,0,0, N/2, N/2);
		System.out.println(result);

	}

	
	private static void solve(int nCnt, int cnt, int d, int dCnt, int x, int y) {
		if(x==0 && y==0) return;
	
		if(dCnt==nCnt) {
			if(++d==4) d=0;
			dCnt=0;
			cnt++;
		}
		if(cnt==2 && nCnt!=N-1) { 
			cnt=0;
			nCnt++;
		}
		
		int nx=x+dx[d];
		int ny=y+dy[d]; 
		
		int send=map[nx][ny];
		int outSend=0;
		
		for(int i=0; i<9; i++) {
		
			int sx=x+movex[d][i];
			int sy=y+movey[d][i];
			
			int plusSend=(int)(send*((double)percent[i]/100));
			outSend+=plusSend;
			if(sx<0|| sy<0|| sx>=N || sy>=N) {
				result+=plusSend; 
				continue;
			}
			map[sx][sy]+=plusSend;
		}
		if(x+movex[d][9]<0 || y+movey[d][9]<0||x+movex[d][9]>=N || y+movey[d][9]>=N) result+=send-outSend;
		else map[x+movex[d][9]][y+movey[d][9]]+=send-outSend; 
		map[nx][ny]=0;
		
		solve(nCnt,cnt,d,dCnt+1,nx,ny);
	}
}