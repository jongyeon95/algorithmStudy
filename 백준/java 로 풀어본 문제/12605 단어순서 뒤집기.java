import java.util.*;
import java.io.*;

public class Main{
	public static HashMap<String,Integer> hm = new HashMap<>();
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n= Integer.parseInt(br.readLine());
		for(int i=0; i<n; i++){
			StringTokenizer stk = new StringTokenizer(br.readLine());
			Stack<String> s = new Stack<>();
			while(stk.hasMoreTokens()){
				s.push(stk.nextToken());
			}
			bw.write("Case #"+(i+1)+":");
			while(!s.isEmpty()){
				bw.write(" "+s.peek());
				s.pop();
			}
			bw.write("\n");

		}
		bw.flush();
		bw.close();
	}

	
}
