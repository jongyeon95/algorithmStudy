import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(stk.nextToken());
		int s=Integer.parseInt(stk.nextToken());
		Queue<Integer> q = new LinkedList<>();

		stk = new StringTokenizer(br.readLine());
		int sum=0;
		int flag=1;
		int answer=n+1;
		int[] list = new int[n];
		
		for(int i=0; i<n; i++){
			list[i]=Integer.parseInt(stk.nextToken());
		}
		q.offer(list[0]);
		sum+=list[0];

		while(!q.isEmpty()){
			if(sum>=s){
				if(q.size()<answer){
					answer=q.size();
				}
				sum-=q.poll();
			}
			else{
				if(flag>=n)
					break;
				sum+=list[flag];
				q.offer(list[flag]);
				flag++;
			}
		}
		if(answer>n){
			answer=0;
		}

		System.out.println(answer);

	}
}