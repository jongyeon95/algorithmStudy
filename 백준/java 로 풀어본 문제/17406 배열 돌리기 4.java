import java.util.*;
import java.io.*;

public class Main{
	public static int[][] map;
	public static int n;
	public static int m;
	public static int k;
	public static int[] commandOrder;
	public static boolean[] commandVisited;
	public static int[][] commandList;
	public static int answer=Integer.MAX_VALUE;
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws IOException{
		inputInit();
		makeOrder(0);
		System.out.println(answer);

	}

	public static void inputInit() throws IOException {
		StringTokenizer stk;
		stk=new StringTokenizer(br.readLine());
		n=Integer.parseInt(stk.nextToken());
		m=Integer.parseInt(stk.nextToken());
		k=Integer.parseInt(stk.nextToken());
		
		map = new int[n][m];
		
		for(int i=0; i<n; i++){
			stk = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++){
				map[i][j]=Integer.parseInt(stk.nextToken());
			}
		}

		commandList= new int[k][3];
		commandOrder=new int[k];
		commandVisited=new boolean[k];

		for(int i=0; i<k; i++){
			stk = new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++){
				commandList[i][j]=Integer.parseInt(stk.nextToken());
			}
		}
	}

	public static void makeOrder(int size){
		if(size==k){
			int result=solved();
			if(result<answer)
				answer=result;
			return;
		}

		for(int i=0; i<k; i++){
			if(!commandVisited[i]){
				commandVisited[i]=true;
				commandOrder[size]=i;
				makeOrder(size+1);
				commandVisited[i]=false;
			}
		}
	}

	public static int solved(){
		int[][] temp=new int[n][m];
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				temp[i][j]=map[i][j];
			}
		}

		for(int i=0; i<k; i++){
			move(temp,commandOrder[i]);
		}

		int result=Integer.MAX_VALUE;

		for(int i=0; i<n; i++){
			int cnt=0;
			for(int j=0; j<m; j++){
				cnt+=temp[i][j];
			}
			if(result>cnt)
				result=cnt;
		}

		return result;

	}

	public static void move(int[][] temp, int index){
		int y=commandList[index][0]-1;
		int x=commandList[index][1]-1;
		
		int startY=commandList[index][0]-commandList[index][2]-1;
		int startX=commandList[index][1]-commandList[index][2]-1;
		int endY=commandList[index][0]+commandList[index][2]-1;
		int endX=commandList[index][1]+commandList[index][2]-1;

		
		while(true){
			Queue<Integer> q = new LinkedList<>();
			for(int i=startX; i<=endX; i++){
				q.offer(temp[startY][i]);
			}
			for(int i=startY+1; i<=endY; i++){
				q.offer(temp[i][endX]);
			}
			for(int i=endX-1; i>=startX; i--){
				q.offer(temp[endY][i]);
			}
			for(int i=endY-1; i>=startY+1; i--){
				q.offer(temp[i][startX]);
			}

			for(int i=startX+1; i<=endX; i++){
				
				temp[startY][i]=q.poll();
			}
			for(int i=startY+1; i<=endY; i++){
				
				temp[i][endX]=q.poll();
			}
			for(int i=endX-1; i>=startX; i--){
				
				temp[endY][i]=q.poll();
			}
			for(int i=endY-1; i>=startY; i--){
				
				temp[i][startX]=q.poll();
			}
			startY++;
			startX++;
			endY--;
			endX--;
			if(startY==y&&startX==x)
				break;
		}
	}


}

