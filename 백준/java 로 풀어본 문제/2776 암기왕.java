import java.util.*;
import java.io.*;

public class Main{
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int testcase = Integer.parseInt(br.readLine());
		while(testcase-- > 0){
			int n=Integer.parseInt(br.readLine());
			HashSet<Integer> hs=new HashSet<>();
			StringTokenizer stk = new StringTokenizer(br.readLine());
			for(int i=0; i<n; i++){
				hs.add(Integer.parseInt(stk.nextToken()));
			}
			int m=Integer.parseInt(br.readLine());
			stk = new StringTokenizer(br.readLine());
			for(int i=0; i<m; i++){
				if(hs.contains(Integer.parseInt(stk.nextToken()))){
					bw.write("1\n");
				}
				else{
					bw.write("0\n");
				}
			}


		}
		bw.flush();
		bw.close();

	}

	
}
