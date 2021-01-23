import java.util.*;
import java.io.*;

public class Main{
	public static void main(String arg[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		PriorityQueue<Integer> pq1 = new PriorityQueue<Integer>(Collections.reverseOrder());
		PriorityQueue<Integer> pq2 = new PriorityQueue<Integer>();
		for(int i=0; i<n; i++){
			int temp =sc.nextInt();
			if(temp>0){
				pq1.offer(temp);
			}
			else{
				pq2.offer(temp);
			}
		}
		int answer=0;
		while(!pq1.isEmpty()){
			int a=pq1.poll();
			if(pq1.isEmpty()){
				answer+=a;
				break;
			}
			int b=pq1.poll();
			if(a*b>a+b)
				answer+=a*b;
			else
				answer+=a+b;
		}

		while(!pq2.isEmpty()){
			int a=pq2.poll();
			if(pq2.isEmpty()){
				answer+=a;
				break;
			}
			int b=pq2.poll();
			answer+=a*b;
		}

			

		System.out.println(answer);

		}
		

}