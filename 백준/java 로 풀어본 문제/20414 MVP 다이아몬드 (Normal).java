import java.util.*;
import java.io.*;

public class Main{
	
	public static int n;
	public static HashMap<Character,Integer> hm = new HashMap<>();
	public static int[] gradeList={0,0,0,0,0,0};
	public static int answer = 0;
	public static int[] list;
	public static boolean check=false;
	public static int[] answerlist;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		hm.put('B',0);
		hm.put('S',1);
		hm.put('G',2);
		hm.put('P',3);
		hm.put('D',4);
		n=Integer.parseInt(stk.nextToken());
		list= new int[n];
		answerlist= new int[n];
		stk = new StringTokenizer(br.readLine());
		for(int i=1; i<5; i++){
			gradeList[i]=Integer.parseInt(stk.nextToken());
		}
		gradeList[5]=gradeList[4]*2+1;
		String input = br.readLine();
		for(int i=0; i<n; i++){
			list[i]=hm.get(input.charAt(i));
		}

		
		dfs(0,0,0);
		

	}
	
	public static void dfs(int index, int sum, int preNum){
		
		if(index==n){
			check=true;
			System.out.print(sum);
			return;
		}
		int start=gradeList[list[index]+1]-1;
		if(start>gradeList[4]){
			start=gradeList[4];
		}
		for(int i=start; i>=0; i--){
			if(check)
				return;
			if(((i+preNum)<gradeList[list[index]+1])&&((i+preNum)>=gradeList[list[index]])){
				dfs(index+1,sum+i,i);
			}
			if(check)
				return;
		}

	}
}