import java.util.*;
import java.io.*;

public class Main
{
	public static int n;
	public static int answer;
	public static int d;
	public static ArrayList<Info> list = new ArrayList<>();
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;
		n=Integer.parseInt(br.readLine());

		answer=0;
		for(int i=0; i<n; i++){
			stk=new StringTokenizer(br.readLine());
			int a=Integer.parseInt(stk.nextToken());
			int b=Integer.parseInt(stk.nextToken());
			list.add(new Info(a,b));
		}
		d=Integer.parseInt(br.readLine());
		Collections.sort(list);
		
		int cnt=0;
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(Info temp : list){
			while(!pq.isEmpty() && pq.peek() < temp.end-d){
				pq.poll();
				cnt--;
			}
			if(temp.start >= temp.end-d){
				cnt++;
				pq.add(temp.start);
			}
			answer = Math.max(answer,cnt);
		}


		System.out.println(answer);

		

	}


}
class Info implements Comparable<Info>{
	
	int start;
	int end;

	public Info(int a, int b){
		this.start=Math.min(a,b);
		this.end=Math.max(a,b);
	}

	@Override
	public int compareTo(Info o){
		if(this.end==o.end){
			return this.start-o.start;
		}
		return this.end-o.end;
	}
}


