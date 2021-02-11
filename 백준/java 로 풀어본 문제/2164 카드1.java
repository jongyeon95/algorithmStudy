import java.util.*;
import java.io.*;

public class Main{

	public static void main(String arg[]){
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		Queue<Integer> q= new LinkedList<>();
		for(int i=1; i<=n; i++){
			q.offer(i);
		}
		StringBuilder sb=new StringBuilder();
		while(!q.isEmpty()){
			sb.append(q.poll()+" ");
			if(!q.isEmpty())
				q.offer(q.poll());
		}
		System.out.println(sb.toString());
	}

}