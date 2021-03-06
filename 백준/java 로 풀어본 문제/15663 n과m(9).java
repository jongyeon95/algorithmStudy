import java.util.*;
import java.io.*;

public class Main{
	public static LinkedHashSet<String> answer = new LinkedHashSet<String>();
	public static int[] list;
	public static boolean[] visited;
	public static int n;
	public static int m;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stk.nextToken());
		m = Integer.parseInt(stk.nextToken());
		list= new int[n];
		visited=new boolean[n];
		stk = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++){
			list[i]=Integer.parseInt(stk.nextToken());
		}
		Arrays.sort(list);
		dfs(0,"");
		for(String temp : answer){
			System.out.println(temp);
		}
	}
	public static void dfs(int size, String result){
		if(size==m){
			answer.add(result);
			return;
		}

		for(int i=0; i<list.length; i++){
			if(!visited[i]){
				visited[i]=true;
				if(size==m-1)
					dfs(size+1,result+list[i]);
				else
					dfs(size+1,result+list[i]+" ");
				visited[i]=false;
			}
		}
	}
}