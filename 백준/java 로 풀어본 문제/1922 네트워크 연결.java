import java.util.*;
import java.io.*;

public class Main{
	public static int[] parent;
	public static int n;
	public static int m;
	public static PriorityQueue<Node> pq= new PriorityQueue<>();

	public static void main(String[] args) throws IOException{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;
		n=Integer.parseInt(br.readLine());
		m=Integer.parseInt(br.readLine());
		parent=new int[n+1];
		int answer=0;

		for(int i=1; i<=n; i++){
			parent[i]=i;
		}

		for(int i=0; i<m; i++){
			stk=new StringTokenizer(br.readLine());
			int start=Integer.parseInt(stk.nextToken());
			int end=Integer.parseInt(stk.nextToken());
			int cost=Integer.parseInt(stk.nextToken());
			pq.offer(new Node(start,end,cost));
		}
		while(!pq.isEmpty()){
			
			Node temp=pq.poll();
			if(union(temp.start,temp.end)){
				answer+=temp.cost;
			}

		}
		System.out.println(answer);
	}

	public static int find(int a){
		
		if(parent[a]==a){
			return a;
		}

		return find(parent[a]);
	}

	public static boolean union(int a, int b){

		int ta=find(a);
		int tb=find(b);
		if(ta==tb)
			return false;
		parent[tb]=ta;
		return true;
	}


}


class Node implements Comparable<Node>{
	
	int start;
	int end;
	int cost;

	public Node(int start, int end, int cost){
		this.start = start;
		this.end=end;
		this.cost=cost;
	}

	@Override
	public int compareTo(Node o){
		return this.cost-o.cost;
	}
}