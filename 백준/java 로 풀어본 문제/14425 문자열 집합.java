import java.util.*;
import java.io.*;

public class Main{
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int answer=0;
		int n = Integer.parseInt(stk.nextToken());
		int m = Integer.parseInt(stk.nextToken());
		HashSet<String> hs = new HashSet<String>();
		for(int i=0; i<n; i++){
			hs.add(br.readLine());
		}
		for(int i=0; i<m; i++){
			if(hs.contains(br.readLine())){
				answer++;
			}
		}
		System.out.print(answer);
	}

	
}
