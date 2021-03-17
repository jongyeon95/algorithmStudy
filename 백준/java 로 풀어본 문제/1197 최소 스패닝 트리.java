import java.util.*;
import java.io.*;

class Grape implements Comparable<Grape>{
	int start;
	int end;
	int weight;

	public Grape(int start, int end, int weight){
		this.start=start;
		this.end=end;
		this.weight=weight;
	}

	@Override
	public int compareTo(Grape o){
		return this.weight-o.weight;
	}

}


public class Main{
	
	public static PriorityQueue<Grape> pq= new PriorityQueue<Grape>();
	public static int[] nodes;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int answer=0;
		int v=Integer.parseInt(stk.nextToken());
		int e=Integer.parseInt(stk.nextToken());
		nodes=new int[v+1];
		for(int i=0; i<=v; i++){
			nodes[i]=i;
		}
		for(int i=0; i<e; i++){
			stk = new StringTokenizer(br.readLine());
			int start=Integer.parseInt(stk.nextToken());
			int end=Integer.parseInt(stk.nextToken());
			int weight=Integer.parseInt(stk.nextToken());
			pq.offer(new Grape(start,end,weight));
		}
		while(!pq.isEmpty()){
			Grape temp=pq.poll();
			if(union(temp.start,temp.end)){
				answer+=temp.weight;
			}
		}
		System.out.print(answer);

	}

	public static int find(int num){
		if(nodes[num]==num)
			return num;
		else{
			return find(nodes[num]);
		}
	}

	public static boolean union(int x, int y){
		int x1=find(x);
		int y1=find(y);
		if(x1==y1)
			return false;
		nodes[y1]=x1;
		return true;
	}
}