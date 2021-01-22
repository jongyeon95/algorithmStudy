import java.io.*;
import java.util.*;

class Emo{
	int count;
	int time;
	int preOrder;
	int clipBoard;

	public Emo(int count,int time, int preOrder,int clipBoard){
		this.count=count;
		this.time=time;
		this.preOrder=preOrder;
		this.clipBoard=clipBoard;
	}
	
}
public class Main{

	public static void main(String arg[]) throws IOException{
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		
		Queue<Emo> q= new LinkedList<Emo>();
		boolean visited[][] = new boolean[1001][1001];

		q.offer(new Emo(1,0,0,0));
		while(!q.isEmpty()){
			Emo temp=q.poll();
			if(temp.count==n){
				System.out.println(temp.time);
				return;
			}
			for(int i=1; i<=3; i++){
				int count=temp.count;
				int time=temp.time;
				int clipBoard=temp.clipBoard;
				if(i==1){
					if(temp.preOrder==1||temp.count>n){
						continue;
					}
					clipBoard=temp.count;
					
				}
				else if(i==2){
					count+=temp.clipBoard;
				}
				else{
					if(temp.count==1){
						continue;
					}
					count--;
				}
				if(count>1000||clipBoard>1000)
					continue;
				if(visited[count][clipBoard])
					continue;
				visited[count][clipBoard]=true;
				q.offer(new Emo(count,time+1,i,clipBoard));
			}
		}
	}

}