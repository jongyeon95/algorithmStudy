import java.util.*;
import java.io.*;

public class Main{
	public static int r;
	public static int c;
	public static int[][] map;
	public static int[] dy={1,1};
	public static int[] dx={-1,1};
	public static int answer;
	
	public static int[][][] dpMap;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		answer=0;
		r=Integer.parseInt(stk.nextToken());
		c=Integer.parseInt(stk.nextToken());
		map=new int[r][c];
		dpMap=new int[2][r][c];

		for(int i=0; i<r; i++){
			String input=br.readLine();
			for(int j=0; j<c; j++){
				map[i][j]=input.charAt(j)-'0';
			}
		}

		for(int k=0; k<2; k++){
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					if(map[i][j]==0)
						continue;
					fillDp(i,j,k);
				}
			}
		}

		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(map[i][j]==1){
					int smallSize = dpMap[0][i][j] <= dpMap[1][i][j] ? dpMap[0][i][j] : dpMap[1][i][j];
					for(int k=smallSize; k>answer; k--){
						int temp=k-1;
						int ty1=i+dy[0]*temp;
						int ty2=i+dy[1]*temp;
						int tx1=j+dx[0]*temp;
						int tx2=j+dx[1]*temp;
						if(dpMap[1][ty1][tx1]>temp&&dpMap[0][ty2][tx2]>temp){
							answer=k;
						}
					}
				
				}
			}
		}

		System.out.print(answer);

	}

	public static void fillDp(int y, int x, int k){
		dpMap[k][y][x]=1;
		int ty=y+dy[k];
		int tx=x+dx[k];
		while(true){
			if(ty<0||tx<0||ty>=r||tx>=c||map[ty][tx]==0){
				break;
			}
			dpMap[k][y][x]++;
			ty=ty+dy[k];
			tx=tx+dx[k];
		}
	} 
}