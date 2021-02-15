import java.util.*;
import java.io.*;

public class Main{
	public static String str[];
	public static boolean visited[];
	public static HashSet<String> hs= new HashSet<>();
	public static int n;
	public static int k;
	public static void main(String arg[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		k=Integer.parseInt(br.readLine());
		str=new String[n];
		visited= new boolean[n];
		for(int i=0; i<n; i++){
			str[i]=br.readLine();
		}
		dfs(0,"");
		System.out.println(hs.size());
	}
	public static void dfs(int cnt, String s){
		if(cnt>=k){
			hs.add(s);
			return;
		}
		for(int i=0; i<n; i++){
			if(!visited[i]){
				visited[i]=true;
				dfs(cnt+1,s+str[i]);
				visited[i]=false;
			}
		}

	}
}