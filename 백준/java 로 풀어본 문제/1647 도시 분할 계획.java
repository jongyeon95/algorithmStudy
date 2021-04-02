import java.util.*;
import java.io.*;

public class Main{
	
	public static int[] parent;
	public static int n;
	public static int m;
	public static PriorityQueue<Node> pq= new PriorityQueue<>();

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		n=Integer.parseInt(stk.nextToken());
		m=Integer.parseInt(stk.nextToken());
		parent=new int[n+1];
		for(int i=1; i<=n; i++){
			parent[i]=i;
		}
		for(int i=0; i<m; i++){
			stk = new StringTokenizer(br.readLine());
			int start=Integer.parseInt(stk.nextToken());
			int end=Integer.parseInt(stk.nextToken());
			int cost=Integer.parseInt(stk.nextToken());
			pq.offer(new Node(start,end,cost));
		}
		System.out.println(solved());

	}

	public static int solved(){
		int answer=0;
		int maxCost=0;
		int cnt=0;
		while(cnt<n-2){
			Node temp= pq.poll();
			if(union(temp.start,temp.end)){
				cnt++;
				answer+=temp.cost;
			}
		}
		return answer;
	}

	public static int find(int node){
		if(parent[node]==node)
			return node;
		parent[node]=find(parent[node]);
		return parent[node];
	}

	public static boolean union(int start, int end){
		int s=find(start);
		int e=find(end);
		if(s==e){
			return false;
		}
		parent[e]=s;
		return true;
	}
}

class Node implements Comparable<Node>{
	int start;
	int end;
	int cost;

	public Node(int start, int end, int cost){
		this.start=start;
		this.end=end;
		this.cost=cost;
	}

	@Override
	public int compareTo(Node o){
		return this.cost- o.cost;
	}
}