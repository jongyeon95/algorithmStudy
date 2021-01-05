import java.io.*;
import java.util.*;

class Worker implements Comparable<Worker>{
	int line;
	int workDate;
	int hurry;
	int index;

	Worker(int l, int w, int h,int i){
		this.line=l;
		this.workDate=w;
		this.hurry=h;
		this.index=i;

	}

	@Override
	public int compareTo(Worker o){
		if(this.workDate==o.workDate){
			if(this.hurry==o.hurry){
				return this.line-o.line;
			}
			return o.hurry-this.hurry;
		}
		return o.workDate-this.workDate;
	}
}

public class Main{
	public static void main(String arg[]) throws IOException{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk= new StringTokenizer(br.readLine());
		int n,m,k;
		n=Integer.parseInt(stk.nextToken());
		m=Integer.parseInt(stk.nextToken());
		k=Integer.parseInt(stk.nextToken());
		ArrayList<Queue<Worker>> list= new ArrayList<>();
		for(int i=0; i<m; i++){
			list.add(new LinkedList<Worker>());
		}
		for(int i=0; i<n; i++){
			stk=new StringTokenizer(br.readLine());
			int workDate=Integer.parseInt(stk.nextToken());
			int hurry=Integer.parseInt(stk.nextToken());
			list.get(i%m).offer(new Worker(i%m,workDate,hurry,i));
		}

		PriorityQueue<Worker> pq= new PriorityQueue<>();
		for(int i=0; i<m; i++){
			if(list.get(i).isEmpty())
				break;
			pq.offer(list.get(i).poll());
		}
		int cnt=0;
		while(true){
			Worker temp=pq.poll();
			if(temp.index==k){
				System.out.println(cnt);
				break;
			}
			cnt++;
			if(!list.get(temp.line).isEmpty()){
				pq.offer(list.get(temp.line).poll());
			}
		}

	}
}