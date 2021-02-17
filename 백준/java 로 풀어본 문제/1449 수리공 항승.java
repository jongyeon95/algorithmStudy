import java.util.*;
import java.io.*;

public class Main{

	static int[] pipe;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.valueOf(st.nextToken());
		int l = Integer.valueOf(st.nextToken());
		
		pipe = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			pipe[i] = Integer.valueOf(st.nextToken());
		}
		
		Arrays.sort(pipe);
		
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(i == n - 1) {
				count++;
				continue;
			}
			
			int hole = pipe[i++];
			while(n > i) {
				if(pipe[i] - hole <= l - 1) {
					i++;
				}
				else {
					break;
				}
			}
			count++;
			i--;
		}
		
		System.out.println(count);
	}
	
	
}