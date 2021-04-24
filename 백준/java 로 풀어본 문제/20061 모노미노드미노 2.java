import java.util.*;
import java.io.*;

public class Main
{
	public static int[][] bMap;
	public static int[][] gMap; 
	public static int n;

	public static void main(String args[]) throws Exception
	{
		bMap=new int[4][10];
		gMap=new int[10][4];

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		StringTokenizer stk;
		int score=0;
		for(int i=0; i<n; i++){
			stk=new StringTokenizer(br.readLine());
			int t=Integer.parseInt(stk.nextToken());
			int y=Integer.parseInt(stk.nextToken());
			int x=Integer.parseInt(stk.nextToken());
			moveDown(y,x,t);
			moveRight(y,x,t);
			score+=clearDown();
			score+=clearRight();
			overCheckDown();
			overCheckRight();
		}
		int cnt=0;
		for(int i=4; i<=9; i++){
			for(int j=0; j<4; j++){
				if(bMap[j][i]==1){
					cnt++;
				}
				if(gMap[i][j]==1){
					cnt++;
				}
			}
		}
		System.out.println(score);
		System.out.println(cnt);


	}

	public static void overCheckDown(){
		int cnt=0;
		for(int i=4; i<=5; i++){
			for(int j=0; j<4; j++){
				if(gMap[i][j]==1){
					cnt++;
					break;
				}
			}
		}
		while(cnt-- > 0){
			for(int i=9; i>=4; i--){
				gMap[i][0]=gMap[i-1][0];
				gMap[i][1]=gMap[i-1][1];
				gMap[i][2]=gMap[i-1][2];
				gMap[i][3]=gMap[i-1][3];
			}
					
		}		
	}
	
	public static void overCheckRight(){
		int cnt=0;
		for(int i=4; i<=5; i++){
			for(int j=0; j<4; j++){
				if(bMap[j][i]==1){
					cnt++;
					break;
				}
			}
		}
		while(cnt-- > 0){
			for(int i=9; i>=4; i--){
				bMap[0][i]=bMap[0][i-1];
				bMap[1][i]=bMap[1][i-1];
				bMap[2][i]=bMap[2][i-1];
				bMap[3][i]=bMap[3][i-1];
			}
					
		}		
	}

	public static int clearDown(){
		int clearCnt=0;
		for(int i=9; i>=6; i--){
			boolean check=true;
			for(int j=0; j<4; j++){
				if(gMap[i][j]==0){
					check=false;
				}
			}
			if(check){
				clearCnt++;
				for(int j=i; j>=4; j--){
					gMap[j][0]=gMap[j-1][0];
					gMap[j][1]=gMap[j-1][1];
					gMap[j][2]=gMap[j-1][2];
					gMap[j][3]=gMap[j-1][3];
				}
				i++;
			}
		}
		return clearCnt;

	}

	public static int clearRight(){
		int clearCnt=0;
		for(int i=9; i>=6; i--){
			boolean check=true;
			for(int j=0; j<4; j++){
				if(bMap[j][i]==0){
					check=false;
				}
			}
			if(check){
				clearCnt++;
				for(int j=i; j>=4; j--){
					bMap[0][j]=bMap[0][j-1];
					bMap[1][j]=bMap[1][j-1];
					bMap[2][j]=bMap[2][j-1];
					bMap[3][j]=bMap[3][j-1];
				}
				i++;
			}
		}
		return clearCnt;

	}

	public static void moveDown(int y, int x, int type){
		int ty=y;
		if(type==1||type==3){
			while(true){
				if(ty+1>9||gMap[ty+1][x]==1){
					gMap[ty][x]=1;
					if(type==3)
						gMap[ty-1][x]=1;
					break;
				}
				ty++;
			}
		}
		else if(type==2){
			while(true){
				if(ty+1>9||gMap[ty+1][x]==1||gMap[ty+1][x+1]==1){
					gMap[ty][x]=1;
					gMap[ty][x+1]=1;
					break;
				}
				ty++;
			}
		}
	}

	public static void moveRight(int y, int x, int type){
		int tx=x;
		if(type==1||type==2){
			while(true){
				if(tx+1>9||bMap[y][tx+1]==1){
					bMap[y][tx]=1;
					if(type==2)
						bMap[y][tx-1]=1;
					break;
				}
				tx++;
			}
		}
		else if(type==3){
			while(true){
				if(tx+1>9||bMap[y][tx+1]==1||bMap[y+1][tx+1]==1){
					bMap[y][tx]=1;
					bMap[y+1][tx]=1;
					break;
				}
				tx++;
			}
		}
	}

			
}


